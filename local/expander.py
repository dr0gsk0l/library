#!/usr/bin/env python3

# This code is based on [ac-lirary](https://github.com/atcoder/ac-library)'s expander.py.

import re
import sys
import argparse
from logging import Logger, basicConfig, getLogger
from os import getenv, environ, pathsep, fspath
from pathlib import Path, PurePath
from typing import List, Set, Optional
from subprocess import call
import pyperclip

logger = getLogger(__name__)  # type: Logger

RED = '\033[91m'
BLUE = '\033[94m'
GREEN = '\033[92m'
END = '\033[0m'

# __（アンダーバー二つ） で始まるものは private
class Expander:
    # re は正規表現を使うためのツール https://note.nkmk.me/python-re-match-search-findall-etc/
    # library_include に以下の正規表現を代入している
    # r'' は raw 文字列 エスケープシーケンスをしなくて良くなる https://note.nkmk.me/python-raw-string-escape/
    # acl と自分のを分けているのは、acl 内の <algorithm> などを探さないようにするため
    
    
    # 正規表現の解説 https://murashun.jp/article/programming/regular-expression.html
    # \s : スペース
    # [~] : ~ 内のいずれか1文字
    # (~) : ~ を一つのグループと見做す あまり気にしなくて良い
    # a-z, A-Z : 小文字,大文字全て
    # * : 直前の文字 0 回以上 最長一致
    # | : OR 前後のいずれかとマッチ (|.cpp) は (∅ OR .cpp)

    # __init__ はコンストラクタ C++ で言えば Expander() と同じ意味
    # self は今いる class(Expander) 自体のことを指し、外部からこの関数を呼ぶ場合には引数に書かなくて ok
    # Expander の変数 lib_paths に引数の lib_paths を代入 List[Path] は型を明示的に書いてる
    # Path は pathlib から import した型
    # lib_paths は list なので、複数のライブラリを渡せる
    def __init__(self, lib_paths: List[Path], acl_compile:bool, replace_endl:bool):
        self.lib_paths = lib_paths
        self.replace_endl = replace_endl
        acl_pattern = 'atcoder/[a-z_]*(|.hpp)'
        drog_pattern = '[/\w]*.cpp'
        if acl_compile:
            self.__library_include_checker = re.compile(r'#include\s*["<]({}|{})[">]\s*'.format(acl_pattern,drog_pattern))
        else:
            self.__library_include_checker = re.compile(r'#include\s*["<]({})[">]\s*'.format(drog_pattern))

    # library の名前を渡して、（見つかれば）そこへのパスを返す
    def __find_library_path(self, library_file_name: str) -> Path:
        for lib_path in self.lib_paths:
            path = lib_path / library_file_name
            if path.exists():
                return path
        logger.error(RED + 'cannot find: {}'.format(library_file_name) + END)
        raise FileNotFoundError()
    
    # include したライブラリ一覧
    __included = set()  # type: Set[Path]

    # acl の include_guard 
    # drogskol library は pragma once を使っているが、acl の expand もしたい為残してる
    __include_guard = re.compile(r'#.*ATCODER_[A-Z_]*_HPP')

    # その行が無視していい行かどうか
    # c++ で *this と書く部分で代わりに具体的な変数名を使ってる感じで、self なのはただの慣例
    def __is_ignored_line(self, line) -> bool:
        if self.__include_guard.match(line):
            return True
        if line.strip() == "#pragma once":
            return True
        if line.strip().startswith('//'):
            return True
        return False

    # library の path を渡して展開する文字列（ライブラリの中身）を返す
    def __expand_library(self, library_file_path: Path) -> List[str]:
        # 既に include されているかを check
        if library_file_path in self.__included:
            logger.info('already included: {}'.format(library_file_path.name))
            return []
        self.__included.add(library_file_path)
        logger.info(BLUE + 'include: {}'.format(library_file_path.name) + END)

        library_source = open(str(library_file_path)).read()

        result = []  # type: List[str]
        for line in library_source.splitlines():
            if self.__is_ignored_line(line):
                continue

            # 展開した文字列の中にさらに include がある場合
            m = self.__library_include_checker.match(line)
            if m:
                name = m.group(1) # match した文字列
                result.extend(self.__expand_library(self.__find_library_path(name)))
                continue

            result.append(line)
        return result
    
    # 外部からはこれが一回呼び出されるだけ
    # source は具体的なプログラム（b.cpp とか）の中身
    # 展開されたコード（combined.cpp）を返す
    def expand(self, source: str) -> str:
        self.__included = set()
        result = []  # type: List[str]
        for line in source.splitlines():
            m = self.__library_include_checker.match(line)
            if m:
                library_path = self.__find_library_path(m.group(1))
                result.extend(self.__expand_library(library_path))
                continue

            if self.replace_endl:
                line = line.replace('endl',"'\\n'")
            result.append(line)
        return '\n'.join(result)


if __name__ == "__main__":
    # logger の設定
    basicConfig(
        format="[%(levelname)s] %(message)s",
        level=getenv('LOG_LEVEL', 'INFO'),
    )

    # コマンドライン引数を設定するためのもの https://qiita.com/kzkadc/items/e4fc7bc9c003de1eb6d0
    # description はコメントみたいなもの　別に書かなくても良い
    parser = argparse.ArgumentParser(description='Expander')

    # add_argument('arg1') と書くと、"python expander.py tomato" で実行すれば arg1 に tomato が代入される
    # help は引数の説明でコメントみたいなもの　別に書かなくても良い "python expander.py --help" をすると各変数の help が表示される
    # '--arg2' と書いた場合はオプション引数になる "--arg2 sarusa" を付ければ arg2 に sarusa が代入される
    # この時 '-a2' と一緒に書けば "-a2 sarusa" でも良くなる（省略形）
    # action='store_true' は引数を取らず、実行時にそれの --arg が呼ばれていたら true が代入される
    # 上の qiita を読むと action や help 以外にも色々あって楽しい
    parser.add_argument('source', nargs='?', default='b.cpp', help='Source File')
    parser.add_argument('--lib', nargs='*', help='Path to Library')
    parser.add_argument('--pbcopy', '-cp', action='store_true', help='output to pbcopy')
    parser.add_argument('--acl', action='store_true', help='expand acl')
    parser.add_argument('--endl', action='store_false', help='not replace endl')
    opts = parser.parse_args()

    print("[INFO] " + GREEN + "expand library" + END)

    lib_paths = []
    if opts.lib:
        for lib in opts.lib:
            lib_paths.append(Path(lib))

    # 環境変数（environ）の 'CPLUS_INCLUDE_PATH' で自分のライブラリのパスを指定したい時に使うものだと思う（https://atcoder.github.io/ac-library/production/document_ja/appendix.html）
    if 'CPLUS_INCLUDE_PATH' in environ:
        lib_paths.extend(map(Path, filter(None, environ['CPLUS_INCLUDE_PATH'].split(pathsep))))
    
    # カレントディレクトリを lib_paths に追加
    lib_paths.append(Path.cwd())
    # Expander の構築
    expander = Expander(lib_paths,opts.acl,opts.endl)
    # コマンドライン引数から source を取り出す
    source = open(opts.source).read()
    # combined.cpp の作成
    output = expander.expand(source)

    # pbcopy が指定されていればクリップボードに出力
    if opts.pbcopy:
        pyperclip.copy(output)
    else:
        with open('combined.cpp', 'w') as f:
            f.write(output)