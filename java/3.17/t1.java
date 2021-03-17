import java.util.Scanner;

public class t1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] martix1 = new int[20][];
        int[][] martix2 = new int[20][];
        int sum;

        System.out.println("请输入第一个矩阵的维数：(先行后列)");
        int row1 = sc.nextInt(); 
        int col1 = sc.nextInt();
        for (int i = 0; i < row1; i++) {
            martix1[i] = new int[col1];
            for (int j = 0; j < martix1[i].length; j++) {
                martix1[i][j] = sc.nextInt();
            }
            System.out.println("第"+(i+1)+"行输入成功");
        }
        System.out.println("第一个矩阵生成成功");

        System.out.println("请输入第二个矩阵的维数：(先行后列)");
        int row2 = sc.nextInt(); 
        int col2 = sc.nextInt();
        if (col1 != row2) {
            System.out.println("前一个矩阵的列数不等于后一个矩阵的行数，两矩阵不能相乘");
            sc.close();
            return;
        }
        for (int i = 0; i < row2; i++) {
            martix2[i] = new int[col2];
            for (int j = 0; j < martix2[i].length; j++) {
                martix2[i][j] = sc.nextInt();
            }
            System.out.println("第"+(i+1)+"行输入成功");
        }
        System.out.println("第二个矩阵生成成功");

        System.out.println("两矩阵相乘结果应为");
        for (int i = 0; i < row1; i++) {
            sum = 0;
            int com = 0;
            for (int j = 0; j < col2; j++) {
                while(com < col1) {
                    sum += martix1[i][com] * martix2[com][j];
                    com++;
                }
                System.out.print(sum+" ");
            }
            System.out.print("\n");
        }

        sc.close();
    }
}