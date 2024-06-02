fetch('http://26.173.109.7:8080/Servlet/servletConfig', {
    method: 'GET',
    headers: {
        Accept: 'application/json',
        'Content-Type': 'application/json'
    },
})
.then(resposta => {
  if (!resposta.ok) {
      throw new Error('Erro ao fazer a solicitação: ' + resposta.statusText);
  }
  return resposta.json();
})
.then(json => { 
  
  json.forEach(produto => {
    
    const codPrd = produto.Cod_prd;
    const precoProduto = produto.Preco_produto;
    const categoriaProduto = produto.Categoria_produto;
    const tamanhoProduto = produto.Tamanho_produto;
    const quantidadeProduto = produto.Quantidade_produto;

    
    console.log('Cod_prd:', codPrd);
    console.log('Preco_produto:', precoProduto);
    console.log('Categoria_produto:', categoriaProduto);
    console.log('Tamanho_produto:', tamanhoProduto);
    console.log('Quantidade_produto:', quantidadeProduto);
    console.log("\n");
});

 })
.catch(error => console.error(error));