/* linker command file for all TI build environments */

SECTIONS 
{
  GROUP: > DDR3_SHARED_EVE
  {
    .memsec_shared_data_eve.1
    .memsec_shared_data_eve.2
    .memsec_shared_data_eve.3
    .memsec_shared_data_eve.4
  }
}
