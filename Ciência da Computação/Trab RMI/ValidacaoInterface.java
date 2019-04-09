import java.rmi.*;

public interface ValidacaoInterface extends Remote {
   public boolean valida(String email) throws RemoteException;
}
