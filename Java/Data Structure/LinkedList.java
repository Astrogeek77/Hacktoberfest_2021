import java.util.Scanner;
  public class LinkedList
{ 
  
   static node head;  
  
   static node p;
   
     static class node
  { 
    int value; 
    
      node next; 
  
      node(int x)
    { 
        value = x;
      
           next=null; 
     }  
  } 
      public void show() 
  
  { 
    node newnode = head; 
     
      while (newnode != null) 
    { 
      System.out.print(newnode.value+" "); 
     
         newnode = newnode.next; 
    } 
  } 
  
    public static void main(String[] args) 
  { 
    
    LinkedList list = new LinkedList(); 
    
    Scanner scan = new Scanner(System.in);
       System.out.println("Enter value for head node :");
          
            int Head = scan.nextInt();
          
    list.head   = new node(Head);
      
         head.next = null;
      
       node head = p;
       
       char ch='Y';
       
      while (ch!='N')
    {
        System.out.println("Enter value for adding node :");
        
             int add = scan.nextInt();
         
      node addnode = new node(add); 
       list.p.next = addnode;
          
          addnode = p;
         
            addnode.next = null;  
         
         System.out.println("Do you want to continue :-");
            ch=scan.next().charAt(0);   
      }
    
    list.show(); 
  } 
}
