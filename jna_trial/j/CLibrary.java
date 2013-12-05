import com.sun.jna.*;
import java.util.Arrays;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: picsolve
 * Date: 05/12/13
 * Time: 12:15
 * To change this template use File | Settings | File Templates.
 */
public interface CLibrary extends Library
{
    public static interface Example20UnionType {
        public static final int UNKNOWN = 0;
        public static final int INTEGER = 1;
        public static final int FLOAT = 2;
        public static final int STRING = 3;
        public static final int STRUCT = 4;
    }
    public static class ExampleStruct extends Structure {
        public static class ByReference extends ExampleStruct implements Structure.ByReference {}

        public int x;
        public String name;

        @Override
        protected List getFieldOrder() {
            return Arrays.asList("x", "name");  //To change body of implemented methods use File | Settings | File Templates.
        }
    }

    public static class Example20Union extends Union {
        public static class ByValue extends Example20Union implements Union.ByValue {};

        public int intnumber;
        public float floatnumber;
        public String stringval;
        public ExampleStruct structval;
    }

    public static class Example20UnionHolder extends Structure {
        public static class ByReference extends Example20UnionHolder implements Structure.ByReference {}

        public int uniontype;
        public Example20Union unionval;

        @Override
        protected List getFieldOrder() {
            return Arrays.asList("uniontype", "unionval");  //To change body of implemented methods use File | Settings | File Templates.
        }

    }

    public static class Example20UnionList extends Structure {
        public static class ByReference extends Example20UnionList implements Structure.ByReference {}

        public int numVals;
        public Example20UnionHolder.ByReference vals;

        @Override
        protected List getFieldOrder() {
            return Arrays.asList("numVals", "vals");  //To change body of implemented methods use File | Settings | File Templates.
        }
    }

    public void example20_send(Example20UnionList.ByReference pList);
}

