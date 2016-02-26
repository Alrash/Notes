package test;

import java.util.*;
import java.lang.Math.*;

public class test 
{
    public static int lengthofLCS(int[] arr)
    {
        // 辅助变量
        int[] MaxV = new int [arr.length+1]; //记录递增子序列 LIS 的末尾元素最小值
        int nMaxLength = 1; 				  //记录当前有序组MaxV的长度
        int [] LIS = new int[arr.length+1];  //LIS[i]记录的是以第i个元素为结尾的最长序列的长度
        
        // 初始化
        MaxV[0] = -100;
        MaxV[nMaxLength] = arr[0];
        LIS[0] = 0;LIS[1] = 1;

        for(int i=1;i<arr.length;i++)
        {
            if(arr[i] >MaxV[nMaxLength])
            {
                MaxV[++nMaxLength] = arr[i];
                /*
                 * 改动
                 * 原来是LIS[i] = LIS[i - 1] + 1;
                 * 根据这个算法，在10进入时，LIS[10] = LIS[9] + 1
                 * LIS[9] = 4，则LIS[10] = 5；而实际LIS[10]应该为6
                 * */
                LIS[i] = Math.max(LIS[i-1], LIS[0]) + 1;
                LIS[0] = Math.max(LIS[i], LIS[0]);		//全组最长的序列长度
            }
            else{
                // 新元素 更小，更有“潜力”，替换大的元素
                int index = binarySearch(MaxV,arr[i],0,nMaxLength);     
                //*     
                LIS[i] =index;
                MaxV[index] = arr[i];
            }
        
            for (int j = 1; j <= nMaxLength; j++)
            	System.out.print(MaxV[j] + " ");
            System.out.print("\n");
        }
        
        System.out.println();
        for (int i = 1; i < arr.length; i++)
        	System.out.print(LIS[i] +  " ");
        System.out.println();
        
        Arrays.sort(LIS);
        return LIS[LIS.length-1];
    }
    
    // 在MaxV数组中查找一个元素刚刚大于arr[i]
    // 返回这个元素的index
    public static int binarySearch(int []arr, int n, int start, int end)
    {
    	/*改动*/
        while(start<end)
        {
            int mid = (start + end)/2;
            if(arr[mid] <= n)
                start = mid+1;
            else 
            	end = mid;
        }
        return end;
    }
    
    public static void main(String[] args) 
    {
        int[] arr = {2,1,5,3,6,4,8,9,7,10};
        System.out.println(lengthofLCS(arr));
    }

}

