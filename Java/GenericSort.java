//A Generic Method that can perform the sorting of any type of data.

import java.util.*;
class GenClass<T>
{
	T[] arr;
	GenClass(T[] ob) 
	{ 
		arr = ob; 
	}
	public void disp(T[] arr)
	{
		System.out.println("Given array elements:\n");
		for(int i=0;i<arr.length;i++)
		{
			System.out.println(arr[i]);
		}
	}
}
public class GenericSort
{
	public static <T extends Comparable<? super T>> void selectionSort(T[] arr)
	{
		for (int i = 0; i < arr.length - 1; ++i)
		{
			int minIndex = i;
			for (int j = i + 1; j < arr.length; ++j)
			{
				if (arr[j].compareTo(arr[minIndex]) < 0)
				{
					minIndex = j;
				}
			}
			T temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
	public static void main(String[] args)
	{
		Integer intArr[] = {10, 6, 2, 8, 16, 25};
		Double dbArr[] = {5.6, 2.4, 1.3, 6.7, 7.8, 8.9};
		Character chArr[] = {'b', 'm', 'r', 'p', 'w', 'g'};
		String stArr[]= {"orange", "apple", "mango", "grapes", "watermelon"};
		GenClass<Integer> iob = new GenClass<Integer>(intArr);
		GenClass<Double> dob = new GenClass<Double>(dbArr);
		GenClass<Character> cob = new GenClass<Character>(chArr);
		GenClass<String> sob = new GenClass<String>(stArr);
		System.out.println("-------------------------------------------------------");
		System.out.println("     CASE I: Input array of Type Integer");
		System.out.println("-------------------------------------------------------");
		iob.disp(intArr);
		selectionSort(intArr);
		System.out.println("\nSorted array:\n");
		System.out.println(Arrays.toString(intArr));
		System.out.println("-------------------------------------------------------");
		System.out.println("     CASE II: Input array of Type Double");
		System.out.println("-------------------------------------------------------");
		dob.disp(dbArr);
		selectionSort(dbArr);
		System.out.println("\nSorted array:\n");
		System.out.println(Arrays.toString(dbArr));
		System.out.println("-------------------------------------------------------");
		System.out.println("     CASE III: Input array of Type Character");
		System.out.println("-------------------------------------------------------");
		cob.disp(chArr);
		selectionSort(chArr);
		System.out.println("\nSorted array:\n");
		System.out.println(Arrays.toString(chArr));
		System.out.println("-------------------------------------------------------");
		System.out.println("     CASE IV: Input array of Type String");
		System.out.println("-------------------------------------------------------");
		sob.disp(stArr);
		selectionSort(stArr);
		System.out.println("\nSorted array:\n");
		System.out.println(Arrays.toString(stArr));
	}
}