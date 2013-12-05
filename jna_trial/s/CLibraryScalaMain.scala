import CLibrary.Example20UnionHolder
import com.sun.jna.Native

object CLibraryScalaMain {

  def main(args:Array[String]) = {

  val clib = Native.loadLibrary("testlib", classOf[CLibrary]).asInstanceOf[CLibrary]


        val ex20listref = new CLibrary.Example20UnionList.ByReference()
        ex20listref.numVals = 4;
        ex20listref.vals = new CLibrary.Example20UnionHolder.ByReference()

        val  ex20holders: Array[Example20UnionHolder] =  ex20listref.vals.toArray(4).asInstanceOf[Array[Example20UnionHolder]]
        ex20holders(0).uniontype = CLibrary.Example20UnionType.INTEGER
        ex20holders(0).unionval.setType(Integer.TYPE)
        ex20holders(0).unionval.intnumber = 31

        ex20holders(1).uniontype = CLibrary.Example20UnionType.FLOAT
        ex20holders(1).unionval.setType(java.lang.Float.TYPE)
        ex20holders(1).unionval.floatnumber = 32.3f

        ex20holders(2).uniontype = CLibrary.Example20UnionType.STRING
        ex20holders(2).unionval.setType(classOf[String])
        ex20holders(2).unionval.stringval = "hello"

        ex20holders(3).uniontype = CLibrary.Example20UnionType.STRING
        ex20holders(3).unionval.setType(classOf[String])
        ex20holders(3).unionval.stringval = "hello2"

        ex20listref.vals.write()

       clib.example20_send(ex20listref)
    }
}
