project('lifesim', 'c',
  version: '0.1.0',
  default_options: ['c_std=c11', 'warning_level=3'])

raylib_dep = dependency('raylib')

sources = files(
  'src/game_of_life.c',
  'src/main.c'
)

includes = include_directories('src')

executable('game-of-life',
  sources,
  include_directories: includes,
  dependencies: raylib_dep,
  install: true)
