import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class QueueExample
{

    public static void main(String arg[]) throws IOException 
    {
        Queue q = new LinkedList();
        
        // Add in Queue
        q.add(23);
        q.add(33);
        System.out.println(q);
        System.out.println("Queue Element :"+q.element());
      
        q.offer(34);
        q.offer(98);
        q.offer(77);

        System.out.println(q);
        System.out.println("Queue Element :"+q.element());
        q.poll();
      
        System.out.println("Queue Element :"+q.element());
        System.out.println("After poll : " + q);
    }
}
