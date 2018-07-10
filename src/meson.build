c24_src = [
  'c24_controls.c',
  'c24_error.c',
  'c24_frame.c',
  'c24_handshake.c',
  'c24_protocol.h',
  'c24_request.c',
  'c24_surface.c',
  'c24_surface_manager.c',
  'c24_vu_meter_mask_request.c',
  'network.c',
  'queue.c',
  'utility.c'
]

c24_inc = files(
  'c24_controls.h',
  'c24_error.h',
  'c24_frame.h',
  'c24_request.h',
  'network.h',
  'c24_handshake.h',
  'c24_surface.h',
  'c24_vu_meter_mask_request.h',
  'queue.h',
  'c24_protocol.h',
  'c24_surface_manager.h'
)

c24_lib = static_library('c24_lib', c24_src, install : true,
    include_directories : c24_includes)

install_headers(c24_inc, subdir : 'c24')
