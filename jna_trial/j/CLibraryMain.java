import com.sun.jna.Native;

public class CLibraryMain {

    public static void main(String [] args) {
        CLibrary clib = (CLibrary) Native.loadLibrary("testlib", CLibrary.class);
        CLibrary.Example20UnionList.ByReference ex20listref = new CLibrary.Example20UnionList.ByReference();

        int ARRAY_SIZE = 5;

        ex20listref.numVals = ARRAY_SIZE;
        ex20listref.vals = new CLibrary.Example20UnionHolder.ByReference();

        CLibrary.Example20UnionHolder[] ex20holders = (CLibrary.Example20UnionHolder[])ex20listref.vals.toArray(ARRAY_SIZE);
        ex20holders[0].uniontype = CLibrary.Example20UnionType.INTEGER;
        ex20holders[0].unionval.setType(Integer.TYPE);
        ex20holders[0].unionval.intnumber = 31;

        ex20holders[1].uniontype = CLibrary.Example20UnionType.FLOAT;
        ex20holders[1].unionval.setType(Float.TYPE);
        ex20holders[1].unionval.floatnumber = 32.3f;

        ex20holders[2].uniontype = CLibrary.Example20UnionType.STRING;
        ex20holders[2].unionval.setType(String.class);
        ex20holders[2].unionval.stringval = "hello";

        ex20holders[3].uniontype = CLibrary.Example20UnionType.STRING;
        ex20holders[3].unionval.setType(String.class);
        ex20holders[3].unionval.stringval = "hello2";

        ex20holders[4].uniontype = CLibrary.Example20UnionType.STRUCT;
        ex20holders[4].unionval.setType(CLibrary.ExampleStruct.class);
        CLibrary.ExampleStruct exampleStruct = new CLibrary.ExampleStruct();
        exampleStruct.name = "foo";
        exampleStruct.x = 10;
        exampleStruct.write();
        ex20holders[4].unionval.structval = exampleStruct;

        ex20listref.vals.write();

        clib.example20_send(ex20listref);
    }
}
