
"""Cryptographic protocols

Implements various cryptographic protocols.  (Don't expect to find
network protocols here.)

Crypto.Protocol.AllOrNothing   Transforms a message into a set of message
                               blocks, such that the blocks can be
                               recombined to get the message back.

Crypto.Protocol.Chaffing       Takes a set of authenticated message blocks
                               (the wheat) and adds a number of
                               randomly generated blocks (the chaff).
"""

__all__ = ['AllOrNothing', 'Chaffing']
__revision__ = "$Id: __init__.py 1.1 2021/12/13 18:26:37CET Wang, David (Wangd3) none  $"
