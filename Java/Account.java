import java.util.Scanner;
public class Account {
	private float CurrentBalance =15000f;
	public static void main(String[] args) {
		Account A = new Account();
		System.out.println("------------------------------------------------");
		System.out.println("Your account balance is : " + A.CurrentBalance);
		Scanner inputDevice = new Scanner(System.in);
		System.out.print("Please enter amount to add in your balance: ");
		float newAmount = inputDevice.nextFloat();
		try{
			float totalAmount = new Account().AddAmount(newAmount);
			System.out.println("Total Account Balance = "+ totalAmount);
			System.out.println("------------------------------------------------");
		}catch (AccountBalanceException a){
			float fdAmount = a.getAccountBalance() - 20000 ;
			System.out.println("Your account balance is more than 20K now, So creating FD of Amount: "+ fdAmount);
			System.out.println("------------------------------------------------");
			new Account().createFixDeposit(fdAmount);
			System.out.println("Account Balance = "+20000);
		}
	}
	public float AddAmount(float amount) throws AccountBalanceException{
		float total = CurrentBalance+amount;
		if (total>20000){
			throw new AccountBalanceException(total);
		}
		return total;
	}
	public void createFixDeposit(float fxAmount){
		//Implimentation of FD creation
	}	
}

class AccountBalanceException extends Exception {
	private float accountBalance ;
	public AccountBalanceException(float f){		
		super();
		this.accountBalance =f;
	}
	public AccountBalanceException(String message){
		super(message);
	}
	public float getAccountBalance(){
		return accountBalance;
	}
}
