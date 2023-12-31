"""Hashing algorithms

Hash functions take arbitrary strings as input, and produce an output
of fixed size that is dependent on the input; it should never be
possible to derive the input data given only the hash function's
output.  Hash functions can be used simply as a checksum, or, in
association with a public-key algorithm, can be used to implement
digital signatures.

The hashing modules here all support the interface described in PEP
247, "API for Cryptographic Hash Functions".

Submodules:
Crypto.Hash.HMAC          RFC 2104: Keyed-Hashing for Message Authentication
Crypto.Hash.MD2
Crypto.Hash.MD4
Crypto.Hash.MD5
Crypto.Hash.RIPEMD
Crypto.Hash.SHA
"""

__all__ = ['HMAC', 'MD2', 'MD4', 'MD5', 'RIPEMD', 'SHA', 'SHA256']
__revision__ = "$Id: __init__.py 1.1 2021/12/13 18:26:26CET Wang, David (Wangd3) none  $"

