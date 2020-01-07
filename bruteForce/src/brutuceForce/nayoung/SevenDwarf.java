package brutuceForce.nayoung;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class SevenDwarf {

   private static int[] height = new int[9];
   private static int count = 0;

   public static void main(String[] args) {

      Scanner sc = new Scanner(System.in);

      int[] combi = new int[9];

      for (int i = 0; i < height.length; i++) {
         height[i] = sc.nextInt();
      }

      sc.close();

      Arrays.sort(height);
      combination(combi, 9, 7, 0, 0);
   }

   public static void combination(int[] combi, int n, int r, int index, int target) {
      if (count != 0) {
         return;
      }
      if (r == 0) {
         int heightSum = 0;
         for (int i = 0; i < index; i++) {
            heightSum += height[combi[i]];
         }
         if (heightSum == 100) {
            ArrayList<Integer> dwarfHeightList = new ArrayList<Integer>();
            for (int i = 0; i < index; i++) {
               dwarfHeightList.add(height[combi[i]]);
            }
            Collections.sort(dwarfHeightList);
            for (int dwarfHeight : dwarfHeightList) {
               System.out.println(dwarfHeight);
            }
            count++;
         } else {
            // heigthSum이 100을 넘으면 
            return;
         }
      } else if (target == n) {
         return;
      } else {
         combi[index] = target;
         // 해당 난쟁이로 뽑은 경우
         combination(combi, n, r - 1, index + 1, target + 1);
         combination(combi, n, r, index, target + 1);
      }
   }

}