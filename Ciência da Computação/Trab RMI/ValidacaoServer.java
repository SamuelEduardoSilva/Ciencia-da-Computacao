import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;

public class ValidacaoServer implements ValidacaoInterface
{
	public String emails[];

	public ValidacaoServer()
    {
		this.emails = new String[]
        {
			"joaomarcos@hotmail.com",
			"luiz@gmail.com",
			"ricardo@hotmail.com",
			"carlos@hotmail.com",
			"eduardo@gmail.com",
			"samuel@gmail.com",
			"jonathan@gmail.com",
			"perses@hotmail.com",
			"gabriel@gmail.com",
			"flavia@hotmail.com"
		};
	}

	public static void main(String[] args)
    {
		try {
			// Instancia o objeto servidor e a sua stub  
			ValidacaoServer server = new ValidacaoServer();
			ValidacaoInterface stub = (ValidacaoInterface) UnicastRemoteObject.exportObject(server, 0);
			
			// Registra a stub no RMI Registry para que ela seja obtida pelos clientes
			Registry registry = LocateRegistry.getRegistry();
			registry.bind("Validacao", stub);
			
			System.out.println("Servidor pronto");
		}
		catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public boolean valida(String email) throws RemoteException
    {
		
		boolean existe = false;

		for(String e : this.emails)
        {
			if(email.equals(e)){
				existe = true;
				break;
			}
		}

		return existe;
	}

}