project('c24', 'c')
cc = meson.get_compiler('c')

c24_includes = include_directories('src')
subdir('src')

if meson.is_subproject()
  # dep to make it easy to use c24 as a Meson subproject
  c24_dep = declare_dependency(
      include_directories : c24_includes,
      link_with : c24_lib)
else
  threads_dep = dependency('threads')
  m_dep = cc.find_library('m')
  executable('c24_example',
      'src/exemple.c',
      link_with : c24_lib,
      include_directories: c24_includes,
      dependencies : [threads_dep, m_dep])

    pkg = import('pkgconfig')
    pkg.generate(name: 'c24',
                  description: 'C24 Control Library',
                  version: '0.1',
                  subdirs : ['c24'],
                  libraries: [c24_lib, '-lpthread', '-lm'])

endif
