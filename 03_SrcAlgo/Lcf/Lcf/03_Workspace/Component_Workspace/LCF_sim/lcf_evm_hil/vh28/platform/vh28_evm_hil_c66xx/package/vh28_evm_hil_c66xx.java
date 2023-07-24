/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-z52
 */
import java.util.*;
import org.mozilla.javascript.*;
import xdc.services.intern.xsr.*;
import xdc.services.spec.Session;

public class vh28_evm_hil_c66xx
{
    static final String VERS = "@(#) xdc-z52\n";

    static final Proto.Elm $$T_Bool = Proto.Elm.newBool();
    static final Proto.Elm $$T_Num = Proto.Elm.newNum();
    static final Proto.Elm $$T_Str = Proto.Elm.newStr();
    static final Proto.Elm $$T_Obj = Proto.Elm.newObj();

    static final Proto.Fxn $$T_Met = new Proto.Fxn(null, null, 0, -1, false);
    static final Proto.Map $$T_Map = new Proto.Map($$T_Obj);
    static final Proto.Arr $$T_Vec = new Proto.Arr($$T_Obj);

    static final XScriptO $$DEFAULT = Value.DEFAULT;
    static final Object $$UNDEF = Undefined.instance;

    static final Proto.Obj $$Package = (Proto.Obj)Global.get("$$Package");
    static final Proto.Obj $$Module = (Proto.Obj)Global.get("$$Module");
    static final Proto.Obj $$Instance = (Proto.Obj)Global.get("$$Instance");
    static final Proto.Obj $$Params = (Proto.Obj)Global.get("$$Params");

    static final Object $$objFldGet = Global.get("$$objFldGet");
    static final Object $$objFldSet = Global.get("$$objFldSet");
    static final Object $$proxyGet = Global.get("$$proxyGet");
    static final Object $$proxySet = Global.get("$$proxySet");
    static final Object $$delegGet = Global.get("$$delegGet");
    static final Object $$delegSet = Global.get("$$delegSet");

    Scriptable xdcO;
    Session ses;
    Value.Obj om;

    boolean isROV;
    boolean isCFG;

    Proto.Obj pkgP;
    Value.Obj pkgV;

    ArrayList<Object> imports = new ArrayList<Object>();
    ArrayList<Object> loggables = new ArrayList<Object>();
    ArrayList<Object> mcfgs = new ArrayList<Object>();
    ArrayList<Object> icfgs = new ArrayList<Object>();
    ArrayList<String> inherits = new ArrayList<String>();
    ArrayList<Object> proxies = new ArrayList<Object>();
    ArrayList<Object> sizes = new ArrayList<Object>();
    ArrayList<Object> tdefs = new ArrayList<Object>();

    void $$IMPORTS()
    {
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
        Global.callFxn("loadPackage", xdcO, "ti.platforms.generic");
        Global.callFxn("loadPackage", xdcO, "xdc.platform");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("vh28_evm_hil_c66xx.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("vh28_evm_hil_c66xx", new Value.Obj("vh28_evm_hil_c66xx", pkgP));
    }

    void Platform$$OBJECTS()
    {
        Proto.Obj po, spo;
        Value.Obj vo;

        po = (Proto.Obj)om.bind("vh28_evm_hil_c66xx.Platform.Module", new Proto.Obj());
        vo = (Value.Obj)om.bind("vh28_evm_hil_c66xx.Platform", new Value.Obj("vh28_evm_hil_c66xx.Platform", po));
        pkgV.bind("Platform", vo);
        // decls 
        om.bind("vh28_evm_hil_c66xx.Platform.Board", om.findStrict("xdc.platform.IPlatform.Board", "vh28_evm_hil_c66xx"));
        om.bind("vh28_evm_hil_c66xx.Platform.Memory", om.findStrict("xdc.platform.IPlatform.Memory", "vh28_evm_hil_c66xx"));
        // insts 
        Object insP = om.bind("vh28_evm_hil_c66xx.Platform.Instance", new Proto.Obj());
        po = (Proto.Obj)om.bind("vh28_evm_hil_c66xx.Platform$$Object", new Proto.Obj());
        Object objP = om.bind("vh28_evm_hil_c66xx.Platform.Object", new Proto.Str(po, true));
        po = (Proto.Obj)om.bind("vh28_evm_hil_c66xx.Platform$$Params", new Proto.Obj());
        om.bind("vh28_evm_hil_c66xx.Platform.Params", new Proto.Str(po, true));
    }

    void Platform$$CONSTS()
    {
        // module Platform
    }

    void Platform$$CREATES()
    {
        Proto.Fxn fxn;
        StringBuilder sb;

        fxn = (Proto.Fxn)om.bind("vh28_evm_hil_c66xx.Platform$$create", new Proto.Fxn(om.findStrict("vh28_evm_hil_c66xx.Platform.Module", "vh28_evm_hil_c66xx"), om.findStrict("vh28_evm_hil_c66xx.Platform.Instance", "vh28_evm_hil_c66xx"), 2, 1, false));
                fxn.addArg(0, "name", $$T_Str, $$UNDEF);
                fxn.addArg(1, "__params", (Proto)om.findStrict("vh28_evm_hil_c66xx.Platform.Params", "vh28_evm_hil_c66xx"), Global.newObject());
        sb = new StringBuilder();
        sb.append("vh28_evm_hil_c66xx$Platform$$create = function( name, __params ) {\n");
            sb.append("var __mod = xdc.om['vh28_evm_hil_c66xx.Platform'];\n");
            sb.append("var __inst = xdc.om['vh28_evm_hil_c66xx.Platform.Instance'].$$make();\n");
            sb.append("__inst.$$bind('$package', xdc.om['vh28_evm_hil_c66xx']);\n");
            sb.append("__inst.$$bind('$index', __mod.$instances.length);\n");
            sb.append("__inst.$$bind('$category', 'Instance');\n");
            sb.append("__inst.$$bind('$args', {name:name});\n");
            sb.append("__inst.$$bind('$module', __mod);\n");
            sb.append("__mod.$instances.$add(__inst);\n");
            sb.append("__inst.externalMemoryMap = __mod.PARAMS.externalMemoryMap;\n");
            sb.append("__inst.customMemoryMap = __mod.PARAMS.customMemoryMap;\n");
            sb.append("__inst.renameMap = __mod.PARAMS.renameMap;\n");
            sb.append("__inst.dataMemory = __mod.PARAMS.dataMemory;\n");
            sb.append("__inst.codeMemory = __mod.PARAMS.codeMemory;\n");
            sb.append("__inst.stackMemory = __mod.PARAMS.stackMemory;\n");
            sb.append("__inst.sectMap = __mod.PARAMS.sectMap;\n");
            sb.append("__inst.peripherals = __mod.PARAMS.peripherals;\n");
            sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
            sb.append("var save = xdc.om.$curpkg;\n");
            sb.append("xdc.om.$$bind('$curpkg', __mod.$package.$name);\n");
            sb.append("__mod.instance$meta$init.$fxn.apply(__inst, [name]);\n");
            sb.append("xdc.om.$$bind('$curpkg', save);\n");
            sb.append("__inst.$$bless();\n");
            sb.append("return __inst;\n");
        sb.append("}\n");
        Global.eval(sb.toString());
        fxn = (Proto.Fxn)om.bind("vh28_evm_hil_c66xx.Platform$$construct", new Proto.Fxn(om.findStrict("vh28_evm_hil_c66xx.Platform.Module", "vh28_evm_hil_c66xx"), null, 3, 1, false));
                fxn.addArg(0, "__obj", (Proto)om.findStrict("vh28_evm_hil_c66xx.Platform$$Object", "vh28_evm_hil_c66xx"), null);
                fxn.addArg(1, "name", $$T_Str, $$UNDEF);
                fxn.addArg(2, "__params", (Proto)om.findStrict("vh28_evm_hil_c66xx.Platform.Params", "vh28_evm_hil_c66xx"), Global.newObject());
        sb = new StringBuilder();
        sb.append("vh28_evm_hil_c66xx$Platform$$construct = function( __obj, name, __params ) {\n");
            sb.append("var __mod = xdc.om['vh28_evm_hil_c66xx.Platform'];\n");
            sb.append("var __inst = __obj;\n");
            sb.append("__inst.$$bind('$args', {name:name});\n");
            sb.append("__inst.$$bind('$module', __mod);\n");
            sb.append("__mod.$objects.$add(__inst);\n");
            sb.append("__inst.externalMemoryMap = __mod.PARAMS.externalMemoryMap;\n");
            sb.append("__inst.customMemoryMap = __mod.PARAMS.customMemoryMap;\n");
            sb.append("__inst.renameMap = __mod.PARAMS.renameMap;\n");
            sb.append("__inst.dataMemory = __mod.PARAMS.dataMemory;\n");
            sb.append("__inst.codeMemory = __mod.PARAMS.codeMemory;\n");
            sb.append("__inst.stackMemory = __mod.PARAMS.stackMemory;\n");
            sb.append("__inst.sectMap = __mod.PARAMS.sectMap;\n");
            sb.append("__inst.peripherals = __mod.PARAMS.peripherals;\n");
            sb.append("for (var __p in __params) __inst[__p] = __params[__p];\n");
            sb.append("__inst.$$bless();\n");
            sb.append("return null;\n");
        sb.append("}\n");
        Global.eval(sb.toString());
    }

    void Platform$$FUNCTIONS()
    {
        Proto.Fxn fxn;

    }

    void Platform$$SIZES()
    {
    }

    void Platform$$TYPES()
    {
        Scriptable cap;
        Proto.Obj po;
        Proto.Str ps;
        Proto.Typedef pt;
        Object fxn;

        cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "vh28_evm_hil_c66xx/Platform.xs");
        om.bind("vh28_evm_hil_c66xx.Platform$$capsule", cap);
        po = (Proto.Obj)om.findStrict("vh28_evm_hil_c66xx.Platform.Module", "vh28_evm_hil_c66xx");
        po.init("vh28_evm_hil_c66xx.Platform.Module", om.findStrict("xdc.platform.IPlatform.Module", "vh28_evm_hil_c66xx"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("CPU", (Proto)om.findStrict("ti.platforms.generic.Platform.Instance", "vh28_evm_hil_c66xx"), $$UNDEF, "wh");
                po.addFxn("create", (Proto.Fxn)om.findStrict("vh28_evm_hil_c66xx.Platform$$create", "vh28_evm_hil_c66xx"), Global.get("vh28_evm_hil_c66xx$Platform$$create"));
                po.addFxn("construct", (Proto.Fxn)om.findStrict("vh28_evm_hil_c66xx.Platform$$construct", "vh28_evm_hil_c66xx"), Global.get("vh28_evm_hil_c66xx$Platform$$construct"));
        fxn = Global.get(cap, "module$use");
        if (fxn != null) om.bind("vh28_evm_hil_c66xx.Platform$$module$use", true);
        if (fxn != null) po.addFxn("module$use", $$T_Met, fxn);
        fxn = Global.get(cap, "module$meta$init");
        if (fxn != null) om.bind("vh28_evm_hil_c66xx.Platform$$module$meta$init", true);
        if (fxn != null) po.addFxn("module$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "instance$meta$init");
        if (fxn != null) om.bind("vh28_evm_hil_c66xx.Platform$$instance$meta$init", true);
        if (fxn != null) po.addFxn("instance$meta$init", $$T_Met, fxn);
        fxn = Global.get(cap, "module$validate");
        if (fxn != null) om.bind("vh28_evm_hil_c66xx.Platform$$module$validate", true);
        if (fxn != null) po.addFxn("module$validate", $$T_Met, fxn);
        po = (Proto.Obj)om.findStrict("vh28_evm_hil_c66xx.Platform.Instance", "vh28_evm_hil_c66xx");
        po.init("vh28_evm_hil_c66xx.Platform.Instance", om.findStrict("xdc.platform.IPlatform.Instance", "vh28_evm_hil_c66xx"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("codeMemory", $$T_Str, "DDR3_C66XX", "wh");
        po.addFld("dataMemory", $$T_Str, "DDR3_C66XX", "wh");
        po.addFld("stackMemory", $$T_Str, "DDR3_C66XX", "wh");
        po.addFld("l2Mode", $$T_Str, "128k", "wh");
        po.addFld("l1PMode", $$T_Str, "32k", "wh");
        po.addFld("l1DMode", $$T_Str, "32k", "wh");
                fxn = Global.get(cap, "getCpuDataSheet");
                if (fxn != null) po.addFxn("getCpuDataSheet", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCpuDataSheet", "vh28_evm_hil_c66xx"), fxn);
                fxn = Global.get(cap, "getCreateArgs");
                if (fxn != null) po.addFxn("getCreateArgs", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCreateArgs", "vh28_evm_hil_c66xx"), fxn);
                fxn = Global.get(cap, "getExeContext");
                if (fxn != null) po.addFxn("getExeContext", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExeContext", "vh28_evm_hil_c66xx"), fxn);
                fxn = Global.get(cap, "getExecCmd");
                if (fxn != null) po.addFxn("getExecCmd", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExecCmd", "vh28_evm_hil_c66xx"), fxn);
                fxn = Global.get(cap, "getLinkTemplate");
                if (fxn != null) po.addFxn("getLinkTemplate", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getLinkTemplate", "vh28_evm_hil_c66xx"), fxn);
        po = (Proto.Obj)om.findStrict("vh28_evm_hil_c66xx.Platform$$Params", "vh28_evm_hil_c66xx");
        po.init("vh28_evm_hil_c66xx.Platform.Params", om.findStrict("xdc.platform.IPlatform$$Params", "vh28_evm_hil_c66xx"));
                po.addFld("$hostonly", $$T_Num, 1, "r");
        po.addFld("codeMemory", $$T_Str, "DDR3_C66XX", "wh");
        po.addFld("dataMemory", $$T_Str, "DDR3_C66XX", "wh");
        po.addFld("stackMemory", $$T_Str, "DDR3_C66XX", "wh");
        po.addFld("l2Mode", $$T_Str, "128k", "wh");
        po.addFld("l1PMode", $$T_Str, "32k", "wh");
        po.addFld("l1DMode", $$T_Str, "32k", "wh");
        po = (Proto.Obj)om.findStrict("vh28_evm_hil_c66xx.Platform$$Object", "vh28_evm_hil_c66xx");
        po.init("vh28_evm_hil_c66xx.Platform.Object", om.findStrict("vh28_evm_hil_c66xx.Platform.Instance", "vh28_evm_hil_c66xx"));
                fxn = Global.get(cap, "getCpuDataSheet");
                if (fxn != null) po.addFxn("getCpuDataSheet", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCpuDataSheet", "vh28_evm_hil_c66xx"), fxn);
                fxn = Global.get(cap, "getCreateArgs");
                if (fxn != null) po.addFxn("getCreateArgs", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getCreateArgs", "vh28_evm_hil_c66xx"), fxn);
                fxn = Global.get(cap, "getExeContext");
                if (fxn != null) po.addFxn("getExeContext", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExeContext", "vh28_evm_hil_c66xx"), fxn);
                fxn = Global.get(cap, "getExecCmd");
                if (fxn != null) po.addFxn("getExecCmd", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getExecCmd", "vh28_evm_hil_c66xx"), fxn);
                fxn = Global.get(cap, "getLinkTemplate");
                if (fxn != null) po.addFxn("getLinkTemplate", (Proto.Fxn)om.findStrict("xdc.platform.IPlatform$$getLinkTemplate", "vh28_evm_hil_c66xx"), fxn);
    }

    void Platform$$ROV()
    {
    }

    void $$SINGLETONS()
    {
        pkgP.init("vh28_evm_hil_c66xx.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "vh28_evm_hil_c66xx"));
        pkgP.bind("$capsule", $$UNDEF);
        pkgV.init2(pkgP, "vh28_evm_hil_c66xx", Value.DEFAULT, false);
        pkgV.bind("$name", "vh28_evm_hil_c66xx");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "vh28_evm_hil_c66xx.");
        pkgV.bind("$vers", Global.newArray());
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['vh28_evm_hil_c66xx'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void Platform$$SINGLETONS()
    {
        Proto.Obj po;
        Value.Obj vo;

        vo = (Value.Obj)om.findStrict("vh28_evm_hil_c66xx.Platform", "vh28_evm_hil_c66xx");
        po = (Proto.Obj)om.findStrict("vh28_evm_hil_c66xx.Platform.Module", "vh28_evm_hil_c66xx");
        vo.init2(po, "vh28_evm_hil_c66xx.Platform", $$DEFAULT, false);
        vo.bind("Module", po);
        vo.bind("$category", "Module");
        vo.bind("$capsule", om.findStrict("vh28_evm_hil_c66xx.Platform$$capsule", "vh28_evm_hil_c66xx"));
        vo.bind("Instance", om.findStrict("vh28_evm_hil_c66xx.Platform.Instance", "vh28_evm_hil_c66xx"));
        vo.bind("Params", om.findStrict("vh28_evm_hil_c66xx.Platform.Params", "vh28_evm_hil_c66xx"));
        vo.bind("PARAMS", ((Proto.Str)om.findStrict("vh28_evm_hil_c66xx.Platform.Params", "vh28_evm_hil_c66xx")).newInstance());
        vo.bind("$package", om.findStrict("vh28_evm_hil_c66xx", "vh28_evm_hil_c66xx"));
        tdefs.clear();
        proxies.clear();
        mcfgs.clear();
        icfgs.clear();
        inherits.clear();
        vo.bind("Board", om.findStrict("xdc.platform.IPlatform.Board", "vh28_evm_hil_c66xx"));
        tdefs.add(om.findStrict("xdc.platform.IPlatform.Board", "vh28_evm_hil_c66xx"));
        vo.bind("Memory", om.findStrict("xdc.platform.IPlatform.Memory", "vh28_evm_hil_c66xx"));
        tdefs.add(om.findStrict("xdc.platform.IPlatform.Memory", "vh28_evm_hil_c66xx"));
        vo.bind("MemoryMap", om.findStrict("xdc.platform.IPlatform.MemoryMap", "vh28_evm_hil_c66xx"));
        vo.bind("$$tdefs", Global.newArray(tdefs.toArray()));
        vo.bind("$$proxies", Global.newArray(proxies.toArray()));
        vo.bind("$$mcfgs", Global.newArray(mcfgs.toArray()));
        vo.bind("$$icfgs", Global.newArray(icfgs.toArray()));
        inherits.add("xdc.platform");
        vo.bind("$$inherits", Global.newArray(inherits.toArray()));
        ((Value.Arr)pkgV.getv("$modules")).add(vo);
        ((Value.Arr)om.findStrict("$modules", "vh28_evm_hil_c66xx")).add(vo);
        vo.bind("$$instflag", 1);
        vo.bind("$$iobjflag", 1);
        vo.bind("$$sizeflag", 1);
        vo.bind("$$dlgflag", 0);
        vo.bind("$$iflag", 1);
        vo.bind("$$romcfgs", "|");
        vo.bind("$$nortsflag", 0);
        Proto.Str ps = (Proto.Str)vo.find("Module_State");
        if (ps != null) vo.bind("$object", ps.newInstance());
        vo.bind("$$meta_iobj", om.has("vh28_evm_hil_c66xx.Platform$$instance$static$init", null) ? 1 : 0);
        vo.bind("$$fxntab", Global.newArray());
        vo.bind("$$logEvtCfgs", Global.newArray());
        vo.bind("$$errorDescCfgs", Global.newArray());
        vo.bind("$$assertDescCfgs", Global.newArray());
        Value.Map atmap = (Value.Map)vo.getv("$attr");
        atmap.seal("length");
        vo.bind("Object", om.findStrict("vh28_evm_hil_c66xx.Platform.Object", "vh28_evm_hil_c66xx"));
        pkgV.bind("Platform", vo);
        ((Value.Arr)pkgV.getv("$unitNames")).add("Platform");
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("module$meta$init", (Scriptable)om.findStrict("vh28_evm_hil_c66xx.Platform", "vh28_evm_hil_c66xx"));
        vo = (Value.Obj)om.findStrict("vh28_evm_hil_c66xx.Platform", "vh28_evm_hil_c66xx");
        Global.put(vo, "CPU", Global.callFxn("create", (Scriptable)om.find("ti.platforms.generic.Platform"), "CPU", Global.newObject("clockRate", 500L, "catalogName", "ti.catalog.c6000", "deviceName", "Vayu", "customMemoryMap", Global.newArray(new Object[]{Global.newArray(new Object[]{"DSP1_L1D", Global.newObject("name", "DSP1_L1D", "base", 0x00f00000L, "len", 0x00008000L, "space", "data", "access", "RW")}), Global.newArray(new Object[]{"DSP1_L1P", Global.newObject("name", "DSP1_L1P", "base", 0x00e00000L, "len", 0x00008000L, "space", "code", "access", "RWX")}), Global.newArray(new Object[]{"DSP1_L2", Global.newObject("name", "DSP1_L2", "base", 0x00800000L, "len", 0x00048000L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"OCMC_RAM1", Global.newObject("name", "OCMC_RAM1", "base", 0x40300000L, "len", 0x00080000L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"DDR3_EVE", Global.newObject("name", "DDR3_EVE", "base", 0x80000000L, "len", 0x01030000L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"DDR3_C66XX", Global.newObject("name", "DDR3_C66XX", "base", 0x82000000L, "len", 0x06000000L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"DDR3_SHARED", Global.newObject("name", "DDR3_SHARED", "base", 0x88000000L, "len", 0x04000000L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"DDD3_CM4", Global.newObject("name", "DDD3_CM4", "base", 0x8c000000L, "len", 0x04000000L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"DDR3_SHARED_EVE", Global.newObject("name", "DDR3_SHARED_EVE", "base", 0x81030000L, "len", 0x00ed0000L, "space", "code/data", "access", "RWX")}), Global.newArray(new Object[]{"DDR3_FUNC_SEC", Global.newObject("name", "DDR3_FUNC_SEC", "base", 0x81f00000L, "len", 0x000f0000L, "space", "code/data", "access", "RWX")})}), "l2Mode", "128k", "l1PMode", "32k", "l1DMode", "32k")));
        Global.callFxn("init", pkgV);
        ((Value.Obj)om.getv("vh28_evm_hil_c66xx.Platform")).bless();
        ((Value.Arr)om.findStrict("$packages", "vh28_evm_hil_c66xx")).add(pkgV);
    }

    public void exec( Scriptable xdcO, Session ses )
    {
        this.xdcO = xdcO;
        this.ses = ses;
        om = (Value.Obj)xdcO.get("om", null);

        Object o = om.geto("$name");
        String s = o instanceof String ? (String)o : null;
        isCFG = s != null && s.equals("cfg");
        isROV = s != null && s.equals("rov");

        $$IMPORTS();
        $$OBJECTS();
        Platform$$OBJECTS();
        Platform$$CONSTS();
        Platform$$CREATES();
        Platform$$FUNCTIONS();
        Platform$$SIZES();
        Platform$$TYPES();
        if (isROV) {
            Platform$$ROV();
        }//isROV
        $$SINGLETONS();
        Platform$$SINGLETONS();
        $$INITIALIZATION();
    }
}