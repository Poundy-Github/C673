r"""
copy_db.py
----------

documentation of copy_db.py
arguments could look like this:
C:\>python copy_db.py "uid=ALGO_DB_USER;pwd=read" "ADMSADMIN" "C:\Users\ui...\Python\testing.sqlite" "^MFC400_SR_CD$"
C:\>python copy_db.py D:\python\exersices\test_db.sqlite "C:\Users\ui...\Python\testing.sqlite" "^MFC400_SR_CD$" -e

argument -e will delete destination table before copying starts

:org:           Continental AG
:author:        Sven Mertens

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:31CET $
"""

# Import Python Modules -----------------------------------------------------------------------------------------------
from os import path as oPath
from sys import path as sPath
from time import clock
from re import compile as recomp
from sqlite3 import Binary
from argparse import ArgumentParser

# Import STK Modules --------------------------------------------------------------------------------------------------
STKDIR = oPath.abspath(r"..\..")
if STKDIR not in sPath:
    sPath.append(STKDIR)
from stk.db.db_common import BaseDB

# main program --------------------------------------------------------------------------------------------------------

if __name__ == '__main__':

    sClock = clock()

    opts = ArgumentParser(description="proggy copies tables from an oracle or sqlite DB to a sqlite DB")
    opts.add_argument("-s", "--sourcedb", dest="src", nargs='+', required=True,
                      help=r'"uid=ALGO_DB_USER;pwd=read" "DEV_ADMIN" or '
                      r'"C:\Users\ui...\Python\input.sqlite" could be used.')
    opts.add_argument("-d", "--destinationdb", dest="dst", required=True,
                      help=r'"C:\Users\ui...\Python\output.sqlite"')
    opts.add_argument("-t", "--tables", dest="tables", required=True,
                      help="RegEx filter specifying which tables to copy")
    opts.add_argument("-e", "--empty", dest="empty", action='store_true', default=False,
                      help="removes all entries from destination table before insertions start")
    opts.add_argument("-v", action="count", dest="verbose", default=0,
                      help="be verbose / increase output verbosity")
    args = opts.parse_args()

    args.src.append("")  # append an empty string at least.
    if len(args.src[1]) > 0 and not args.src[1].endswith('.'):
        args.src[1] += '.'
    try:
        if args.verbose > 0:
            print("%.3f: opening src DB" % (clock()))
        srcdb = BaseDB(args.src[0], args.src[1])
        if args.verbose > 0:
            print("%.3f: opening dst DB" % (clock()))
        dstdb = BaseDB(args.dst, "")
        tregx = recomp(args.tables)

        if srcdb is None or dstdb is None or tregx is None:
            raise Exception("parameters seem to be wrong!")
    except Exception as ex:
        print(str(ex))
        exit(-1)

    tables = [t for t in srcdb.GetTableNames() if tregx.match(t)]
    print("%.3f: tables found: %s" % (clock(), ", ".join(tables)))
    totRecs = 0
    errs = 0
    for t in tables:
        try:
            lns = 0
            if args.empty is True:
                dstdb.execute("delete from %s" % (t))
            det = srcdb.GetColumns(t)
            nms = '"' + '", "'.join([d[0] for d in det]) + '"'
            enc = []
            for c in det:
                if "CHAR" in c[1] or "DATE" in c[1] or "TIME" in c[1]:
                    enc.append(0)
                elif "LOB" in c[1] or"FILE" in c[1]:
                    enc.append(1)
                else:
                    enc.append(2)
            # enc = [True if "CHAR" in c[1] or "DATE" in c[1] or "TIME" in c[1] else False for c in det]
            tocp = srcdb.execute('select count(*) from %s' % (t))[0][0]
            if args.verbose > 0:
                print(("%.3f: processing table %s (%d rows)..." + (" "*13)) % (clock(), t, tocp)),
            else:
                print("%.3f: processing table %s with %d rows..." % (clock(), t, tocp))
            for r in srcdb.execute('select %s from %s' % (nms, srcdb.table_prefix + t), subspace=False):
                try:
                    vals = []
                    for ri in range(len(r)):
                        if r[ri] is not None:
                            if enc[ri] == 0:
                                vals.append("'" + r[ri].replace("'", "''") + "'")
                            else:
                                vals.append(r[ri])
                        else:
                            vals.append("null")
                        # vals.append(("'"+str(r[ri])+"'" if enc[ri] else str(r[ri])) if r[ri] is not None else "null")
                    instr = [("?" if isinstance(s, bytearray) else str(s)) for s in vals]
                    if "?" in instr:
                        dstdb.execute('insert into "%s" (%s) values(%s)' % (dstdb.table_prefix + t,
                                                                            nms, ", ".join(instr)),
                                      [Binary(b) for b in vals if isinstance(b, bytearray)], subspace=False)
                    else:
                        dstdb.execute('insert into "%s" (%s) values(%s)' % (dstdb.table_prefix + t,
                                                                            nms, ", ".join(instr)), subspace=False)
                    lns += 1
                    if args.verbose > 0:
                        print(("\b"*13) + "%6d (%2d%%)" % (lns, int(lns * 100 / tocp))),
                except Exception, ex:
                    print("ERROR: %s" % ex)
                    errs += 1
            if args.verbose > 0:
                print("\b\b0 " if lns == 0 else "")
            totRecs += lns
        except Exception, ex:
            print("ERROR: %s!" % ex)

    print("%.3f: %d records copied and %d errors, time taken: %ds" % (clock(), totRecs, errs, clock() - sClock))

"""
CHANGE LOG:
-----------
$Log: copy_db.py  $
Revision 1.1 2021/12/13 17:55:31CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.1 2013/11/13 16:24:44CET Mertens, Sven (uidv7805) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/cmd/project.pj
"""
