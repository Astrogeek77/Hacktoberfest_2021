package queuearrayapp;

 
public class QueueArrayApp {

     
    public static void main(String[] args) {
        // TODO code application logic here
        QueueArray x=new QueueArray(5);
        x.display();
        x.enqueue(2);
        x.enqueue(5);
        x.enqueue(3);
        x.display();
        try{
        x.dequeue();
        x.display();
        x.enqueue(23);
        x.enqueue(17);
        x.enqueue(38);
        x.enqueue(45);
         System.out.println("Peek is "+x.peek());
        }catch(Exception e){
            System.out.println(e.toString());
        }
       
        
       
    }
    
}

class QueueArray{
private int maxSize;
private int[] queArray;
private int front;
private int rear;
private int nItems;

public QueueArray(int s){
this.queArray = new int[s];
this.maxSize = s;
this.front = 0;
this.rear = -1;
this.nItems = 0;

}

public boolean isEmpty(){
return this.nItems == 0;    
}

public boolean isFull(){
return this.nItems == this.maxSize; 
        }

public int size(){
return this.nItems;
}

public void enqueue(int value){
if(isFull()){
    System.out.println("Queue is full cannot enqueue");
    return;
}
if(this.rear==this.maxSize-1){
this.rear=0;
}else{
this.rear++;
}
//rear = (rear+1)%maxSize;
this.queArray[rear] = value;
this.nItems++;
}

public int dequeue()throws Exception{
if(isEmpty()){
    throw new Exception("Queue is empty cannot remove."); 
}
int removedItem = this.queArray[front];
if(this.front==this.maxSize-1){
this.front=0;
}else{
front++;
}
//front=(front+1)%maxSize;
front++;
nItems--;
return removedItem;
}

public int peek()throws Exception{
if(isEmpty()){
throw new Exception("Queue is empty cannot get peek value.");
}
return this.queArray[this.front];
}

public void display(){
    if(isEmpty()){
        System.out.println("Queue is epty nothing to print");
        return;
    }
int i=this.front;
while(i!=rear){
    System.out.print(this.queArray[i]+" ");
    if(i==maxSize-1){
    i=0;    
}else {
   i++;
}
    //i=(i+1)%maxSzize;
}
    System.out.print(this.queArray[rear]);
    System.out.println("");
}

}
