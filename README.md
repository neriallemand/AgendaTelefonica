# AgendaTelefonica
Implementação de uma agenda em C++.

- Mudanças feitas após a apresentação:
  
   * Alteração do metodo de remoção, para que ao invés de atribuir NULL a posição, atribua um ponteiro para o objeto que antes era apontado pela ultima posição ocupada do vetor;
  
   * Remoção dos testes (this->contatos[i] == NULL), visto que agora nenhuma posição entre o inicio e o ultimo valera NULL;
    
   * Mensagem de confirmação na remoção, exibindo o contato a ser removido;
   
- Mudanças que serão feitas num futuro breve: 

   * Implementação de metodos de Salvar/Carregar a agenda em um arquivo;
