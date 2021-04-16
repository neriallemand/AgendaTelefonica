# AgendaTelefonica
Implementação de uma agenda em C++.

- Mudanças feitas após a apresentação:
  
   * Alteração do metodo de remoção, para que ao invés de atribuir NULL a posição, atribua o endereço do contato que antes era apontado pela ultima posição ocupada do vetor;
  
   * Remoção dos testes (this->contatos[i] == NULL), visto que agora nenhuma posição entre o inicio e o ultimo valera NULL;
    
   * Mensagem de confirmação na remoção, exibindo o contato a ser removido;
   
- Mudanças que serão feitas num futuro breve: 

   * Implementação de metodos de Salvar/Carregar a agenda em um arquivo;

- Foram criados na main ambos o conjunto de operações pedidos pela questão, e um loop para possibilitar um conjunto de testes maior sem necessitar recompilar o código multiplas vezes
