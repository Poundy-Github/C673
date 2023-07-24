/* linker command file for all TI build environments */

SECTIONS 
{
  GROUP: > DDR3_SHARED
  {
    .memsec_shared_data.1
    .memsec_shared_data.2
    .memsec_shared_data.3
    .memsec_shared_data.4
  }
}
