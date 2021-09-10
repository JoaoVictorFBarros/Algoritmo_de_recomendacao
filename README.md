# Algoritmo de recomendação
Trabalho final de AED I

   Os algoritmos de recomendação são extremamente difundidos atualmente, pois eles facilitam a captação da atenção de
usuários com a sugestão de produtos que ele mesmo demostrou interesse, sendo muito mais eficiêntes de que por exemplo
a Tv, que apresenta conteúdos e anúncios que tentam agradar o público em geral mas que não atente os interesses específicos 
dos mesmos. 

   O objetivo do trabalho portanto é desenvolver um algoritmo de reomendação de jogos baseado em informações que o 
usuário queira fornecer a fim de que baseado em seus interesses lhe seja fornecido conteúdos personalizados. O tipo de 
recomendação foi escolhido devido ao fato de que os video games são o setor que mais movimenta o mercado da indústria
do entretenimento.

   O trabalho foi desenvolvido no sistema operacional Windows 10 e foi compilado no Dev C++. Seu funcionamento é baseado
em um banco de dados no qual são armazanados os nomes dos jogos, assim como uma classificação, de 0 a 100, de relação entre 
esse e uma determindada categoria. Existem 8 categorias, sendo elas:  Ação e aventura, Tiro, E-sports, RPG, mundo aberto, 
simulador, estratégia e multi-jogador. Cada usuário possui também um grau de afinidade, de 0 a 100, com cada uma dessas
categorias, o qual é atualizado quando este demonstra interesse por uma das recomendações.

Menu principal: 

![Menu](https://github.com/JoaoVictorFBarros/Algoritmo_de_recomendacao/blob/Imagens/Menu.png)

Dados:

1[Dados](https://github.com/JoaoVictorFBarros/Algoritmo_de_recomendacao/blob/Imagens/Dados.png)

   Ao criar um novo usuário é solicitado um username, que não pode já ter sido escolhido, assim como uma senha, a qual será
criptografada antes de ser armazenada, a partir de um sistema baseado na cifra de Vigenère, porém a partir da tabela ASCII, ao 
invés do alfabeto. Assim toda vez que o usuário logar em sua conta, lhe será solicitada a senha, que será também criptografada e 
comparada com a armazenada, assim o único método de entrar em uma conta é de posse da senha, mesmo que alguém tenha acesso aos dados
armazenados, copiar a senha criptografada e tentar usá-la para acessar o perfil do usuário não funcionaria.

Tela de Log In

![LogIn](https://github.com/JoaoVictorFBarros/Algoritmo_de_recomendacao/blob/Imagens/logIn.png)

   Um método de otmização de tempo e memória do processo de busca e verifição de username e senha é dispor os objetos da 
classe usuário em uma pilha dinâmica, na qual sempre que um usuário acessa sua conta, ele é colocado no topo da pilha, assim 
usuários mais frequentes estarão sempre próximos ao topo, reduzindo o tempo de busca destes, em um próximo log in.

   Ao iniciar-se o programa o banco de dados é carregado na memória RAM e é organizado em uma lista dinâmica, visando também
não consumir memória desnecessariamente. A partir dele, quando necessário é calculado para cada item da lista uma pontuação, a 
partir de uma média ponderada, onde o valores são a classificação dos jogos em cada categoria e os pesos são o grau de afinidade
do usuário com as mesmas. A lista é então reordenada em ordem decrescente a partir dessa pontuações a partir de um algoritmo de 
ordenação baseado no mergeSort, assim possuíndo um custo computacional, em todos o casos de n * log n (log na base 2), sendo n o 
tamanho da lista. O mergeSort foi escolhido justamente por ter um custo fixo independente da disposição inicial dos dados, pois 
nesse caso, eles são dispostos de forma totalmente imprevisível.

# Segue uma descrição mais detalhada de cada uma das classes, métodos e funções implementados: 

# Classe Cliente:

   Um objeto Cliente tem um construtor, e dois métodos,sendo eles "getAfin()" e "altAfin()". O método "getAfin()" tem custo constante
 e retorna o vetor com valores de classificação de categorias de jogos segundo as avaliações do usuário. O método "altAfin()" é usado
 para alterar os valores desse vetor.
	
# Classe Pilha:

   Um objeto de Pilha armazena objetos da classe Cliente. A classe Pilha possui os métodos "empilhar()", "desempilhar()", "salvar()", 
"carregar()", "inverter()", "buscar()", "moverTopo()" e "imprimir()". No início  da execução, o método "carregar()" é chamado. Ele lê o
arquivo "clientes.txt", no qual são salvos, através do método "salvar()", os dados dos clientes após cada execução do programa. Após isso,
o próprio método "carregar()" cria uma pilha dinâmica  de objetos Cliente com esses dados. O custo desse método é linear com relação ao tamanho
do txt, ou seja, theta de N,sendo N o número de linhas do arquivo. O método salvar também tem custo linear theta de N. No caso desse método, N 
seria o número de clientes da pilha.

   O método "moverTopo()" tem como objetivo mover o último cliente logado para o topo da pilha. Esse método tem custo linear relacionado à distância
do cliente ao topo da pilha. O método "buscar()", verifica se o Cliente fornecido existe e se a senha digitada está correta. O método "buscar()" 
também tem custo linear com relação à distância do cliente ao topo da pilha. O método mover topo, no geral, tem o intúito de reduzir o custo de 
"buscar()", pois se espera que os clientes mais ativos sempre estejam no topo da pilha.

   Os métodos empilhar, desempilhar e imprimir fazem exatamente o que seus nomes sugerem. O método "inverter()", por sua vez, é usado em "salvar()", para
que a pilha seja salva no arquivo de modo que "carregar()" crie a pilha com a ordem correta. O custo de "inverter()" é linear e depende de 3N, sendo N o 
número de clientes da pilha.
	
# Classe lista:

   Um objeto Lista tem os métodos "add()", "remover()", "zerar()", "iniciar()", "imprimir()", "reordenar()","merge()" e "mergeSort()".
Os métodos "add()", "remover()" e "imprimir()" fazem exatamente o que seus nomes sugerem. 

   O método "iniciar()" é equivalente ao "carregar()" da classe Pilha, porém o N de "iniciar()" se refere ao número de linhas do arquivo 
"Dados.txt". Nesse arquivo, estão armazenados nomes de jogos e suas classificações em cada categoria. O método
transforma essas informações em uma lista dinâmica de Itens. Um Item é um objeto de uma struct Item, que tem como
atributos um string, que recebe o nome do jogo e um vetor que recebe as classificações.

   O método "zerar()" libera o espaço alocado da memória e deleta a lista.

   O método "reordenar()" é responsável pela ordenação dos itens da lista em ordem decrescente em relação à relevância desses para o usuário
logado. Ele chama o método "mergeSort()", o qual se chama recursivamente até dividir os itens na menor fração possível. A partir disso, o método
merge é chamado para ordenar cada uma das frações e, após isso, frações maiores, até reconstruir a lista, agora ordenada. O custo completo do método
de ordenação Merge Sort, N * log n.
	
# Funções:

# Criptografar:
   A função criptografar recebe a senha de um cliente como parâmetro e a criptografa. Essa função é usada no "signIn" para que a senha do novo cliente
seja salva no txt já criptografada. Ela também é usada no "login" em "buscar()" para codificar a senha informada pelo usuário e, então, comparar a 
senha já codificada com a do arquivo.
   Essa função usa uma palavra chave pra codificar as senhas. A lógica da codificação é similar a da cifra de Vigenère, porém tendo como base a 
tabela ASCII, e não simplesmente o alfabeto. O custo computtacional associado é de 2*N, pois existem 2 loops de "for" de 0 a N, sendo o primeiro 
responsável por substituir a string de entrada pela palavra-chave repetidamente, fracionando-a se necessário. O segundo a partir de uma 
associação da string original e da substituída, gera uma nova string, cujo caracteres representam essa combinação.

# logIn:
   É usada para logar o cliente. Ele usa "buscar()" pra verificar se o usuário e a senha informados estão corretos, e "moverTopo()" pra mover o cliente
  logado para o topo.

# signIn:
   Essa função cria um novo cliente. Primeiro ela recebe nome e senha. Após isso, o usuário é questionado sobre seus gêneros de jogos preferidos e, a 
partir de suas escolhas, um vetor de preferências é criado.
	
# interface:
   Apresenta recomendações geradas a partir de "reordenar()" e permite ao usuário, ver mais recomendações, enviar feedback e sair. Caso seja enviado um 
feedback as recomendações são recalculadas, a partir dos novos valores de afinidade, que são calculados como o peso do item selecionado, em cada uma das
categorias, menos 50, assim tendo valores positivos e negativos, dividido pela taxa, definida no cabeçalho. Esse valor é então somado a 1 e o resultado é 
obitido pelo seu produto pela afinidade anterior do usuário.

