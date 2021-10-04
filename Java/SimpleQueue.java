//Implementing a Simple Queue

import java.util.Scanner;

class Queue 
{ 
	private static int front, rear, capacity; 
	private static int queue[]; 
	Queue(int c) 
	{ 
		front = rear = 0; 
		capacity = c; 
		queue = new int[capacity]; 
	} 
	//to insert elements at rear of queue
	void queueEnqueue(int data) 												
	{ 
		if (capacity == rear) 
		{ 
			System.out.printf("\nQueue is full\n"); 
			return; 
		} 

		else 
		{ 
			queue[rear] = data; 
			rear++; 
		} 
		System.out.println("\nElement inserted.\n");
		return; 
	} 
	//to delete elements from front of queue 
	void queueDequeue() 													
	{ 
		if (front == rear) 
		{ 
			System.out.printf("\nQueue is empty\n"); 
			return; 
		} 
		// shift all the elements from index 2 till rear to the right by one 
		else 
		{ 
			for (int i = 0; i < rear - 1; i++) 
			{ 
				queue[i] = queue[i + 1]; 
			} 
			// store 0 at rear indicating there's no element 
			if (rear < capacity) 
				queue[rear] = 0; 
			rear--; 
		} 
		System.out.println("\nElement deleted.\n");
		return; 
	} 
	//to display all the elements of queue 
	void queueDisplay()  													
	{ 
		int i; 
		if (front == rear) 
		{ 
			System.out.printf("\nQueue is Empty\n"); 
			return; 
		} 
		for (i = front; i < rear; i++) 
		{ 
			System.out.printf(" %d <-- ", queue[i]); 
		} 
		return; 
	} 
	//to display front element
	void queueFront() 													
	{ 
		if (front == rear) 
		{ 
			System.out.printf("\nQueue is Empty\n"); 
			return; 
		} 
		System.out.printf("\nFront Element is: %d", queue[front]); 
		return; 
	} 
} 

public class SimpleQueue 
{
	public static void main(String[] args) 
	{ 
		System.out.println("\nEnter size of queue : ");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Queue q = new Queue(n);
		outer:
		{
			while(true)
			{
				System.out.println("\nEnter your choice");
				System.out.println("1.Enqueue");
				System.out.println("2.Dequeue");
				System.out.println("3.Display Queue");
				System.out.println("4.Display Front element");
				System.out.println("5.Exit");
				int type_of_op = sc.nextInt();							
				switch(type_of_op)
				{
				case 1: 
					System.out.println("\nEnter element : ");
					int data = sc.nextInt();    
					q.queueEnqueue(data);
					break;
				case 2: 
					q.queueDequeue();
					break;
				case 3:
					q.queueDisplay();
					break;
				case 4: 
					q.queueFront();
					break;	
				case 5:
					break outer;
				default: 
					System.out.println("\nWrong choice"); 
					return ;
				}
			
			}
		}
		sc.close();
	} 
}

