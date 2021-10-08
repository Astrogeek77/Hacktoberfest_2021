public class HeapSort {
	public void sort(int arr[])
	{
		int len = arr.length;

		for (int i = len / 2 - 1; i >= 0; i--)
			heapify(arr, len, i);

		for (int i = len - 1; i > 0; i--) {
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;

			heapify(arr, i, 0);
		}
	}

	void heapify(int arr[], int len, int i)
	{
		int largest = i; 
		int l = 2 * i + 1; 
		int r = 2 * i + 2; 

		if (l < len && arr[l] > arr[largest])
			largest = l;

		if (r < len && arr[r] > arr[largest])
			largest = r;

		if (largest != i) {
			int swap = arr[i];
			arr[i] = arr[largest];
			arr[largest] = swap;

			heapify(arr, len, largest);
		}
	}

	static void printArray(int arr[])
	{
		int len = arr.length;
		for (int i = 0; i < len; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	public static void main(String args[])
	{
		int arr[] = { 12, 11, 13, 5, 6, 7 };
		int n = arr.length;

		HeapSort ob = new HeapSort();
		ob.sort(arr);

		System.out.println("Sorted array is");
		printArray(arr);
	}
}
