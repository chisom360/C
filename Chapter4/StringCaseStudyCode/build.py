#!/usr/bin/python3

from fabricate import *

sources = ['fig11_09', 'String']

def build():
    compile()
    link()

def compile():
    for source in sources:
        run('g++', '-c', source+'.cpp')

def link():
    objects = [s+'.o' for s in sources]
    run('g++', '-o', 'program', objects)

def clean():
    autoclean()

main()
