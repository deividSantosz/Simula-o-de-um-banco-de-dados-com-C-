
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;


struct Cliente {
	int numeroCliente;
	string nome;
};
struct Endereco {
	int nrCliente;
	string logradouro;
	int numero;
	string bairro;
	string cidade;
};

// variaveis globais
int incrementoId = 1, verifica =0;
int contCliente=0;// se estiver em 0 nÃ£o tem cliente adicionado.
int contEndereco=0; // se estiver em 0 endereÃ§o nÃ£o tem endereÃ§o atribuido;


//Prototipos das funÃ§oes
Cliente inserirCliente();
Endereco inserirEndereco(int);  
void imprimirCliente(Cliente *, int);
void imprimirClientetxt (Cliente*, int);
void imprimirEndereco(Endereco*, int);
void imprimirEnderecotxt (Endereco*, int);
Cliente removerCliente (Cliente* , int, Endereco*, int);
Endereco removerEndereco (Endereco*, int, int);


int main(){
    int opcao, escolha; 
    Cliente cadastroCliente[100];
    Endereco endereco[100];
    int cont = 0, contEnd =0;
    int idRemo;
    int IMP=0;

	cout << "\n----------------------------------- BEM VINDO --------------------------------------------"<<endl;
	do {
	
		cout << "\nQual tabela voce quer manipular? \n 1-Cliente \n 2- Endereco\n 0 - Sair \nOP: ";
		cin >> opcao;
		
		switch (opcao) {
        	case 1:
                cout << "\nO que voce deseja fazer? \n 1 - Inserir \n 2 - Exclusao \n 3 - Imprimir\n";
                cin >> escolha;
				//Inserir	
				if(escolha == 1) { 

                    cont++; // toda vez que inserir cont vai contar, para podermos saber o tamanho do vetor
                    
                    if(cont==1){ // if para se caso for a primeira inserção
		        	    for (int i = cont; i <=cont; i++){
                            cadastroCliente[i] = inserirCliente();
                            contCliente++;
                         }   imprimirCliente(cadastroCliente, cont);
                    }else{ // else para caso seja a segunda ou mais inserções, para nao perdemos nem sobreescrever o vetor
                        for (int i = cont ; i <= cont; i++){
                            cadastroCliente[i] = inserirCliente();
                            contCliente++;
                        }
                        imprimirCliente(cadastroCliente, cont);
                    }
                
				}
                //exclusao 
                if (escolha == 2)
                {   
                    imprimirCliente(cadastroCliente, cont);
                    cout << "\nAVISO!!!!!!!!!!!!!!!!\nCaso o cliente tenha enderecos cadastrados, tambem sera deletado os enderecos armazenados desse cliente." << endl;
                    removerCliente (cadastroCliente, cont, endereco, contEnd);
                    
	
                    cont--; // cont -- porque será excluido, então o tamanho diminui em 1.
                    contEnd--;
                    cout << "\n\n\tTABELA CLIENTE: \n\n";
                    imprimirCliente(cadastroCliente, cont);
                    cout << "\n\n\tTABELA ENDERECO: \n\n" << endl;
                    imprimirEndereco(endereco, contEnd);
                   
                    
                }
                
                //impressao 
                if(escolha == 3){
                   cout<<"[1] Para Imprimir txt \n[2] Para imprimir na tela"<<endl;
                   cin>>IMP;
                   if(IMP==1)	imprimirClientetxt (cadastroCliente, cont); // imprimir arquivo txt
                   if(IMP==2)	imprimirCliente(cadastroCliente, cont); // imprimir toda a tabela cliente
                }
                break;
                
            case 2:
				cout << "\nO que voce deseja fazer? \n 1 - Inserir \n 2 - Exclusao \n 3 - Imprimir\n";
                cin >> escolha;
				
                if(escolha==1) {
                	if(contCliente==0){ 
					cout<<"\nNenhum Cliente Cadastrado, Insira um Cliente: "<<endl;
					cont++;
                    
                    if(cont==1){
		        	    for (int i = cont; i <=cont; i++){
                            cadastroCliente[i] = inserirCliente();
                            contCliente++;											// todo esse IF(linha 104 a 121) é para caso tente inserir endereço sem ter nenhum cliente cadastrado.
                         }   imprimirCliente(cadastroCliente, cont);				// dai chamamos a função inserir e repetimos todo o processo que é feito na inserção. 
                    }else{
                        for (int i = cont ; i <= cont; i++){
                            cadastroCliente[i] = inserirCliente();
                            contCliente++;
                        }
                        imprimirCliente(cadastroCliente, cont);
                    }
					cout<<"\nContinue inserindo na tabela Endereco "<<endl;
				}
                    int id;    
                    cout<<"\nInforme o id do cliente: "; 
					cin>>id;
					for(int k=0; k<cont; k++){ 								// for para pecorrer e if para verificar se o id digitado é valido.
						while(id < 0 || id> incrementoId-1){			// verificação se o ID é válido, precisa ser maior que zero e menor que a quantidade de linhas da tabela.
							cout<<"\nID nao existe!! \nDigite Novamente o ID: "<<endl;
							cin>>id;
				}		
			}
				cout<<"\n	ID valido.\nContinue inserindo na tabela Endereco....\n"<<endl; 
				
	            
                    for (int i = 1; i <= cont; i++) {
                        if (cadastroCliente[i].numeroCliente == id){
                            contEnd++; // esse cont é para saber quantos endereços foram inseridos
                            contEndereco++;									
                            if (verifica == 0){
                                for (int i = contEnd; i <= contEnd; i++){							//inserção da tabela endereço repete a logica da tabela cliente.
                                    endereco[i] = inserirEndereco(id);
                                }   
                            }else {
                                for (int i = contEnd; i <= contEnd; i++){
                                    endereco[i] = inserirEndereco(id);
                                    contEndereco++;
                                }
                                    
                            }
                                
                        }
                    }
                    imprimirEndereco(endereco,contEnd);
                }
                if(escolha ==2) {
                    if(contCliente==0){
					cout<<"\nNenhum cliente cadastrado, insira um cliente: "<<endl;
					cont++;
                    
                    if(cont==1){
		        	    for (int i = cont; i <=cont; i++){
                            cadastroCliente[i] = inserirCliente();
                            contCliente++;																// todo esse IF(linha 155 a 173) é para caso tente inserir endereço sem ter nenhum cliente cadastrado.
                         }   imprimirCliente(cadastroCliente, cont);									// dai chamamos a função inserir e repetimos todo o processo que é feito na inserção. 
                    }else{
                        for (int i = cont ; i <= cont; i++){
                            cadastroCliente[i] = inserirCliente();
                            contCliente++;
                        }
                        imprimirCliente(cadastroCliente, cont);
                    }
					cout<<"\nContinue a remocao na tabela endereco... "<<endl;		
				}
				 if(contEndereco==0){														
					cout<<"\nNenhum endereco cadastrado\nVamos comecar a inserir um endereco: "<<endl;			//esse if é para verificar se tem algum endereço cadastrado antes do usuario querer deletar.
					cont++;
                    
                int id;    
                    cout<<"\nInforme o id do cliente: "; 									// se nao tiver nenhum endereço cadastrado, pedimos para o usuario inserir um endereço.
					cin>>id;
					for(int k=0; k<cont; k++){
						while(id < 0 || id> incrementoId-1){		// verificação pra saber se o login é válido
							cout<<"\nID nao existe!! \nDigite Novamente o ID: "<<endl;
							cin>>id;
				}		
			}
				cout<<"\n ID Valido.\nContinue inserindo na tabela Endereco...\n"<<endl;
				
	            
                    for (int i = 1; i <= cont; i++) {
                        if (cadastroCliente[i].numeroCliente == id){
                            contEnd++;
                            contEndereco++;
                            if (verifica == 0){						//aqui a inserção na tabela endereço depois da verificação se o id digitado foi válido.
                                for (int i = contEnd; i <= contEnd; i++){
                                    endereco[i] = inserirEndereco(id);
                                }   
                            }else {
                                for (int i = contEnd; i <= contEnd; i++){
                                    endereco[i] = inserirEndereco(id);
                                    contEndereco++;
                                }
                                    
                            }
                                
                        }
                    }
					cout<<"Continue a remocao na tabela Endereco "<<endl;
				}
                    imprimirEndereco(endereco, contEnd);
                    
                    cout << "\nDigite o ID do cliente que deseja remover o endereco" << endl;
					cin>>idRemo; 
					
                    removerEndereco (endereco, contEnd, idRemo);
                    contEnd--; 
                    imprimirEndereco(endereco, contEnd);
                
				}
                if(escolha == 3) {
                	int opEndereco =0;
                	cout << "[1] Imprimir tabela toda\n[2] Imprimir de um cliente especifico\n[3] imprimir txt" << endl;
                	cin >> opEndereco;
                	
                	if(opEndereco == 1) {
						imprimirEndereco(endereco,contEnd); // impressao de toda a tabela endereço
					}
					if(opEndereco == 2) {
						int idEnd =0;
							cout << "Digite o ID do cliente que voce deseja imprimir os enderecoos" << endl;
								cin >> idEnd;
						
							cout << "_________________________________________________________________________________________________________________________________" << endl;
    						cout << "|\t\t\t\t\t\t\t\t\tEndereco\t\t\t\t\t\t|" << endl;
   							cout << "_________________________________________________________________________________________________________________________________" << endl;
   							cout << "|\tID Cliente\t|\tNumero Casa\t|\t\tlogradouro\t\t|\tcidade\t\t|\tbairro\t|"<< endl;
    						cout << "_________________________________________________________________________________________________________________________________" << endl;
    						
						for (int i = 1; i <= contEnd; i++) { // for para pecorrer
    						if(idEnd==endereco[i].nrCliente){ // condição para imprimir o endereço de um cliente especifico. 
       							cout << "|\t\t"<< endereco[i].nrCliente <<"\t|\t\t" << endereco[i].numero << "\t|\t\t" << endereco[i].logradouro<< "\t\t|\t" << endereco[i].cidade << "\t\t|" << endereco[i].bairro << "\t|" << endl;
               			}
					}
   				}    
					if(opEndereco == 3){
						imprimirEnderecotxt (endereco, contEnd); //impressao do txt
						}		
					}
        		}
    		}while (opcao!=0);

    return 0; 
}


Cliente inserirCliente() {
	Cliente clienteIn; 
    clienteIn.numeroCliente = incrementoId;   			//incremento id é uma variavel global e o id do cliente será sempre incrementado de forma automatica para nao ter duplicidade.
	incrementoId++;
	
    cout << "Digite o Nome: ";
    cin.ignore();
	getline(cin, clienteIn.nome);

    return clienteIn; 
}

void imprimirCliente(Cliente cadastroCliente[], int cont){
    
    cout << "_________________________________________________" << endl;
	cout << "|\t\t\tCliente "<<"\t\t|" << endl;
	cout << "_________________________________________________" << endl;
    cout << "|\tID\t|\tNome\t\t\t|"<< endl;
    cout << "_________________________________________________" << endl;
    for (int i = 1; i <= cont; i++) {
        for(int j = 0; j < 1; j++) {					// dois for de impressao para poder imprimir num formato de matriz.
            if(i>0) {

            }
            cout << "|\t" << cadastroCliente[i].numeroCliente << "\t|\t" << cadastroCliente[i].nome << "\t\t|" << "\n" << endl;
        }
    }      
}
void imprimirClientetxt (Cliente cadastroCliente[], int cont){
    
    ofstream arquivo; // criei uma variavel do tipo arquivo (pode ser do tipo arquivo por causa da include fstream).
    
    arquivo.open ("tabelaCliente.txt");               // vou criar o txt.
	
	arquivo << "_________________________________________________" << endl;
	arquivo << "|\t\t\tCliente "<<"\t\t|" << endl;
	arquivo << "_________________________________________________" << endl;
    arquivo << "|\tID\t|\tNome\t\t\t|"<< endl;
    arquivo << "_________________________________________________" << endl;
    for (int i = 1; i <= cont; i++) {
        for(int j = 0; j < 1; j++) {
            if(i>0) {

            }
            arquivo << "|\t" << cadastroCliente[i].numeroCliente << "\t|\t" << cadastroCliente[i].nome << "\t\t|" << "\n" << endl;
        }
    }      
}

Endereco inserirEndereco(int id) {
    Endereco endCliente;
    verifica++;
	
    endCliente.nrCliente = id;
	cout << "\nDigite o Numero da Casa: ";
	cin>>endCliente.numero;
	cout << "Digite o logradouro: ";
	cin.ignore(); 											// inserção padrão, lembrando que o for fica na main.
	getline(cin, endCliente.logradouro); 
	cout << "Digite o bairro: ";
	getline(cin, endCliente.bairro); 
	cout << "Digite a cidade: ";
	getline(cin, endCliente.cidade); 
				
    return endCliente;
}

void imprimirEndereco(Endereco end[], int cont){
    int i, j; 

	cout << "_________________________________________________________________________________________________________________________________" << endl;
    cout << "|\t\t\t\t\t\t\t\t\tEndereco\t\t\t\t\t\t|" << endl;
   	cout << "_________________________________________________________________________________________________________________________________" << endl;
    cout << "|\tID Cliente\t|\tNumero Casa\t|\t\tlogradouro\t\t|\tcidade\t\t|\tbairro\t|"<< endl;
    cout << "_________________________________________________________________________________________________________________________________" << endl;
    
    for (i = 1; i <= cont; i++) {

        	cout << "|\t\t"<< end[i].nrCliente <<"\t|\t\t" << end[i].numero << "\t|\t\t" << end[i].logradouro<< "\t\t|\t" << end[i].cidade << "\t\t|" << end[i].bairro << "\t|" << endl;
               
    }      
}
void imprimirEnderecotxt (Endereco end[], int cont){
    int i, j; 
	
	ofstream arquivo; // criei uma variavel do tipo arquivo (pode ser do tipo arquivo por causa da include fstream).
    arquivo.open ("tabelaEndereco.txt");               // vou criar o txt.
	
	arquivo << "_________________________________________________________________________________________________________________________________" << endl;
    arquivo << "|\t\t\t\t\t\t\t\t\tEndereco\t\t\t\t\t\t|" << endl;
   	arquivo << "_________________________________________________________________________________________________________________________________" << endl;
    arquivo << "|\tID Cliente\t|\tNumero Casa\t|\t\tlogradouro\t\t|\tcidade\t\t|\tbairro\t|"<< endl;
    arquivo << "_________________________________________________________________________________________________________________________________" << endl;
    
    for (i = 1; i <= cont; i++) {					//impressao em formato de matriz, por isso dois for.
        for(j = 0; j < 1; j++) {
        	arquivo << "|\t\t"<< end[i].nrCliente <<"\t|\t\t" << end[i].numero << "\t|\t\t" << end[i].logradouro<< "\t\t|\t" << end[i].cidade << "\t\t|" << end[i].bairro << "\t|" << endl;
               
        }
    }      
}

Cliente removerCliente (Cliente cadastroCliente[], int cont, Endereco cadastroEndereco[], int contEnd) {
    int idRemo, i, j; 

    cout << "\nDigite o ID do cliente que voce deseja remover" << endl;
	cin>>idRemo; 

	for ( i = 1; i <= cont; i++) // for para pecorrer 
	{
		if (cadastroCliente[i].numeroCliente == idRemo) // if para verificar se o id que o cliente digitou esta na tabela endereço
		{
			for(j = i; j <= cont - 1; j++){ // cont -1 porque como vamos remover, o tamanho do vetor será -1.
				    cadastroCliente[j].numeroCliente =  cadastroCliente[j+1].numeroCliente; 
                    cadastroCliente[j].nome = cadastroCliente[j+1].nome; 						//j+1 para a gente poder mudar a posição do vetor, para que o vetor da frente vá pro lugar do vetor que foi removido
			}																					// e dessa forma o outro indice do vetor deixa de existir.
		
            return (*cadastroCliente);
            
        }else {
        	cout << "\nERRO! Esse ID nao existe\n"; 					
        	removerCliente(cadastroCliente, cont, cadastroEndereco, contEnd);			// caso o id nao seja valido, mensagem de erro e chamamos a função remover novamente.
		}
		
		if(cadastroEndereco[i].nrCliente == idRemo) {
			removerEndereco(cadastroEndereco, contEnd, idRemo);			// esse if ja verifica se o cliente que esta sendo deletado tem um endereço, para chamarmos a função remover endereço assim que o cliente tambem for deletado.
		}
	}  
	   	  
}
Endereco removerEndereco (Endereco cadastroEndereco[], int cont, int idRemo) {
    int i, j; 
																	// aqui seguimos a mesma logica do deletar cliente

	for ( i = 1; i <= cont; i++) // for para pecorrer
	{
		if (cadastroEndereco[i].nrCliente == idRemo) 		//if para verificar se o id que o usuario digitou existe.
		{
			for(j = i; j <= cont - 1; j++){ // cont -1 porque como será deletado, o tamanho do vetor vai diminuir em 1.
			
				    cadastroEndereco[j].nrCliente = cadastroEndereco[j+1].nrCliente; 
                    cadastroEndereco[j].logradouro = cadastroEndereco[j+1].logradouro;
					cadastroEndereco[j].numero = cadastroEndereco[j+1].numero; 						//j+1 para a gente poder mudar a posição do vetor, para que o vetor da frente vá pro lugar do vetor que foi removido
					cadastroEndereco[j].bairro = cadastroEndereco[j+1].bairro; 						// e dessa forma o outro indice do vetor deixa de existir.
					cadastroEndereco[j].cidade = cadastroEndereco[j+1].cidade;  
			}
            return (*cadastroEndereco);
        }
	}  
	    cout << "\nERRO! Esse ID nÃ£o existe\n"; 
	    cin>>idRemo;												// se por acaso o id nao existor, pedimos para o cliente digitar novamente e recomeçar o processo de deletar.
        removerEndereco(cadastroEndereco, cont, idRemo);
		  
}

