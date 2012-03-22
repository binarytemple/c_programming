import java.io.File;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.Arrays;

class JavaTest {

	/**
	 * Adds the specified path to the java library path
	 * 
	 * @param pathToAdd
	 *            the path to add
	 * @throws Exception
	 */
	public static void addLibraryPath(String pathToAdd) throws Exception {
		System.out.println("Adding library path:" + pathToAdd);
		final Field usrPathsField = ClassLoader.class
				.getDeclaredField("usr_paths");
		usrPathsField.setAccessible(true);

		// get array of paths
		final String[] paths = (String[]) usrPathsField.get(null);

		// check if the path to add is already present
		for (String path : paths) {
			if (path.equals(pathToAdd)) {
				return;
			}
		}

		// add the new path
		final String[] newPaths = Arrays.copyOf(paths, paths.length + 1);
		newPaths[newPaths.length - 1] = pathToAdd;
		usrPathsField.set(null, newPaths);

		// The alternative means of twiddling the library include path.
		// set sys_paths to null
		// final Field sysPathsField = ClassLoader.class
		// .getDeclaredField("sys_paths");
		// sysPathsField.setAccessible(true);
		// sysPathsField.set(null, null);
	}

	public static void main(String argv[]) throws IOException, Exception {
		addLibraryPath(new File(".").getCanonicalPath() + "/libs/");

		System.out.println("Loading library");
		System.loadLibrary("area");
		System.out.println("Library loaded");

		System.out.println(area.area_of_square(2));
		System.out.println(area.area_of_circle(3));
	}
}
