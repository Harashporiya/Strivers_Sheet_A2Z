import java.util.ArrayList;
import java.util.Arrays;

public class zero_one_matrix {
    public static void main(String args[]) {
        ArrayList<ArrayList<Integer>> mat = new ArrayList<>();
        mat.add(new ArrayList<>(Arrays.asList(0, 0, 0)));
        mat.add(new ArrayList<>(Arrays.asList(0, 1, 0)));
        mat.add(new ArrayList<>(Arrays.asList(1, 1, 1)));

        int n = mat.size();

        ArrayList<ArrayList<Integer>> vis = new ArrayList<>();
        vis.add(n,0);

        System.out.println(mat.size());
    }

}