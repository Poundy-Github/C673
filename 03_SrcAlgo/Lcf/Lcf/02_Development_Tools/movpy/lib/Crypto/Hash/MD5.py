
# Just use the MD5 module from the Python standard library

__revision__ = "$Id: MD5.py 1.1 2021/12/13 18:26:27CET Wang, David (Wangd3) none  $"

from md5 import *

import md5
if hasattr(md5, 'digestsize'):
    digest_size = digestsize
    del digestsize
del md5

