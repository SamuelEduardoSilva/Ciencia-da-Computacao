import java.rmi.registry.*;
import java.util.*;
import java.io.*;

public class ValidacaoClient {
   public static void main(String[] args) {
		String host = (args.length < 1) ? null : args[0];
		
		System.out.println("\n************************");
		System.out.println("*                      *");
		System.out.println("*  VALIDACAO DE EMAIL  *");
		System.out.println("*                      *");
		System.out.println("************************");
		
		try {
			
			// Obtem uma referencia para o registro do RMI
			Registry registry = LocateRegistry.getRegistry(host);

			// Obtem a stub do servidor
			ValidacaoInterface stub = (ValidacaoInterface) registry.lookup("Validacao");
			
			Scanner scanner = new Scanner(System.in);

			System.out.printf("\nEntre com seu e-mail: ");

			String email = scanner.next();

			String msg = stub.valida(email) ? "Correto" : "Incorreto";

			System.out.println("Mensagem do servidor: " + msg); 
		 
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}