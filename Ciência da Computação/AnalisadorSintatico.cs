using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Compilador
{
    class AnalisadorSintatico
    {
        int infinito = 0x3f3f3f3f;
        List<Token> tokens;
        List<String> codigo;
        List<NaoTerminais> naoterminais;
        List<Gramatica> gramaticas;

        Dictionary<string, bool> map;
        public AnalisadorSintatico(List<String> code)
        {
            /// Cria código de tokens
            codigo = code;
            
            ////////////////////////////////////////////////////////////////////

            /// gera os nós terminais (tokens)
            string[] lines = System.IO.File.ReadAllLines(@"Tokens.txt");
            map = new Dictionary<string, bool>();
            tokens = new List<Token>();
            foreach (string line in lines)
            {
                String[] subs = line.Split('&');
                Token x = new Token(subs[0], subs[1], subs[2]);
                map[subs[0]] = true;
                tokens.Add(x);
            }

            ////////////////////////////////////////////////////////////////
            //// gera as gramáticas
            gramaticas = new List<Gramatica>();
            lines = System.IO.File.ReadAllLines(@"Gramaticas.txt");

            foreach (string line in lines)
            {
                String[] subs = line.Split(' ');

                Gramatica a1 = new Gramatica();
                a1.Nome = subs[0];
                List<String> nos = new List<String>();
                for (int z = 1 ; z < subs.Length; z++)
                    nos.Add(subs[z]);
                a1.Nos = nos;

                gramaticas.Add(a1);
                
            }
            ///////////////////////////////////////////////////////
            /// Gera os nós não terminais
            naoterminais = new List<NaoTerminais>();

            /// Adiciona as gramaticas aos nos nao terminais também!
            foreach (Gramatica g in gramaticas)
            {
                NaoTerminais n = new NaoTerminais();
                n.Nome = g.Nome;
                List<String> l = g.Nos;

                List<List<String>> nods = new List<List<String>>();
                nods.Add(l);
                n.Nos = nods;
                naoterminais.Add(n);
                
            }

            lines = System.IO.File.ReadAllLines(@"NaoTerminais.txt");

            foreach (string line in lines)
            {
                String[] subs = line.Split('&');

                NaoTerminais n = new NaoTerminais();
                n.Nome = subs[0];

                String[] subs2 = subs[1].Split('|');
                List<List<String>> tudo = new List<List<string>> ();
                foreach (string no in subs2)
                {
                    String[] subs3 = no.Split(' ');
                    List<String> eoq = new List<string>();
                    foreach(string h in subs3)
                    {
                        Console.WriteLine(h);
                        eoq.Add(h);
                    }
                    tudo.Add(eoq);
                }
                n.Nos = tudo;

                
             
                naoterminais.Add(n);

            }
            

            ///////////////////////////////////////////////////////////////
        }

        public int OlhaTerminal(string node, int pos)
        {
            int ans = 0;

            for (int i = 0; i < naoterminais.Count; i++)
            {
               
                if (naoterminais[i].Nome == node)
                {
                    
                    NaoTerminais f = naoterminais[i];
               
                    for (int j = 0; j < f.Nos.Count; j++)
                    {
                        bool bateu = false;
                        int antigoans = ans;
                       
                        for (int k = 0; k < f.Nos[j].Count; k++)
                        {
                            string atual = f.Nos[j][k];
                          
                            if (map.ContainsKey(atual))
                            {
                                
                                if (pos + ans >= codigo.Count)
                                {
                                    ans = infinito;
                                    break;
                                }
                                if (atual == codigo[pos + ans])
                                {
                                    
                                    bateu = true;
                                    ans++;
                                }
                                else
                                {
                                    
                                    bateu = false;
                                    break;
                                }
                            }
                            else
                            {
                               
                                int ahs = OlhaTerminal(atual, pos + ans);
                                
                               
                                if (ahs < infinito)
                                {
                                    ans += ahs;
                                    bateu = true;
                                }
                                else
                                {
                                    bateu = false;
                                    break;
                                }
                                    
                            }
                        }

                        if (!bateu) ans = antigoans;
                        else break;
                    }
                    break;
                }
            }
            if (ans == 0)
                return infinito;
            return ans;
        }
        public bool analiza()
        {
            int contAbre = 0;
            foreach (string x in codigo)
            {
                if (x == "abre_ch")
                    contAbre++;
                else if(x == "fecha_ch")
                {
                    if (contAbre > 0) contAbre--;
                    else
                    {
                       // Console.WriteLine()
                        return false;
                    }
                }
            }
            if (contAbre > 0) return false;
            int grammar = -1;
            for (int i = 0; i < codigo.Count;)
            {
                grammar = -1;
               
                string x = codigo[i];
                
                if (grammar == -1)
                {
                    for (int j = 0; j < gramaticas.Count; j++)
                    {
                        Gramatica z = gramaticas[j];

                       
                      
                        if (z.Nos[0] == x)
                        {
                            grammar = j;
                            //    i++;
                        }

                    }
                }
                if (grammar == -1)
                {
                    Console.Write("Entrei aqui ein - 1");
                    return false;
                }
           
                if (gramaticas[grammar].Nome == "ENTRE_CHAVES")
                {

                    
                  
                    i++;

                    if (i >= codigo.Count)
                        return false;
                    string atual = codigo[i];
                  
                    int abertos = 1;
                    while (abertos != 0)
                    {
                        
                        if (atual == "abre_ch")
                        {
                            i++;
                            atual = codigo[i];
                            abertos++;
                            continue;
                        }
                        if (atual == "fecha_ch")
                        {
                            i++;
                            if(i < codigo.Count)
                            atual = codigo[i];
                            abertos--;
                            continue;
                        }
                        for (int j = 0; j < gramaticas.Count; j++)
                        {
                            Gramatica z = gramaticas[j];

                         

                            if (z.Nos[0] == atual)
                            {
                                grammar = j;
                                break;
                            }
                        }
                        Console.WriteLine("Começando a gramatica " + gramaticas[grammar].Nome);
                        for (int j = 0; j < gramaticas[grammar].Nos.Count; j++)
                        {
                            if (i >= codigo.Count)
                            {
                            
                                return false;

                            }
                            string agora = gramaticas[grammar].Nos[j];

                            if (map.ContainsKey(agora))
                            {
                               
                                if (codigo[i] == agora)
                                {

                                    i++;
                                }

                                else
                                {
                                  
                                    return false;
                                }

                            }
                            else
                            {
                                //  Console.WriteLine(agora);


                                int ans = OlhaTerminal(agora, i);

                              
                                if (ans < infinito) i += ans;
                                else
                                {
                                    
                                    return false;
                                }


                            }
                        }
                        if (i >= codigo.Count) return false;
                        atual = codigo[i];
                        
                       
                    }
                   
                //    i++;

                 continue;
                }
               
                for (int j = 0; j < gramaticas[grammar].Nos.Count; j++)
                {
                    if (i >= codigo.Count)
                    {
                        //Console.Write("Entrei aqui ein - 2");
                        return false;
                        
                    }
                    string agora = gramaticas[grammar].Nos[j];
                    
                    if (map.ContainsKey(agora))
                    {
                      
                        if (codigo[i] == agora)
                        {
                            
                            i++;
                        }
                            
                        else
                        {
                           // Console.Write("asdsadjsaidjasidjasidjiasjdiasdjiasjdiasjdisadiasjd");
                            return false;
                        }
                            
                    }
                    else
                    {
                        


                        int ans = OlhaTerminal(agora, i);
                       
                        if (ans < infinito) i += ans;
                        else
                        {
                          //  Console.Write("Entrei aqui ein - 4");
                            return false;
                        }


                    }
                }
                grammar = -1;
            }
            
            return true;
        }
        /*
        private static void Main(string[] args)
        {
            AnalisadorSintatico a = new AnalisadorSintatico();
            
            if (a.analiza())
                Console.WriteLine("Deu MUITO BOM!");
            else
                Console.WriteLine("Deu ruim demais, alguém me ajuda");
                
        }
        */
    }
}
