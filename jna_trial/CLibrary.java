

public interface CLibrary extends Library {
 
   public static interface Example20UnionType {
        public static final int UNKNOWN = 0;
        public static final int INTEGER = 1;
        public static final int FLOAT = 2;
        public static final int STRING = 3;
    }
        public static class Example20Union extends Union {
                public static class ByValue extends Example20Union implements Union.ByValue {};

                public int intnumber;
                public float floatnumber;
                public String stringval;
        }

        public static class Example20UnionHolder extends Structure {
                public static class ByReference extends Example20UnionHolder implements Structure.ByReference {}

                public int uniontype;
                public Example20Union unionval;
        }

        public static class Example20UnionList extends Structure {
                public static class ByReference extends Example20UnionList implements Structure.ByReference {}
                public int numVals;
                public Example20UnionHolder.ByReference vals;
        }
    
        public void example20_send(Example20UnionList.ByReference pList);
}

