
# Just use the SHA module from the Python standard library

__revision__ = "$Id: SHA.py 1.1 2021/12/13 18:26:27CET Wang, David (Wangd3) none  $"

from sha import *
import sha
if hasattr(sha, 'digestsize'):
    digest_size = digestsize
    del digestsize
del sha
