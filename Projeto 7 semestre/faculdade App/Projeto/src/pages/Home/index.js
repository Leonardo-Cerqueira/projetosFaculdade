import React from 'react';
import {Image, Text, View, TextInput, TouchableOpacity, Alert} from 'react-native';

import estilos from './style';
import caminhao from '../../../assets/caminhao.png';
import caixa from '../../../assets/caixa.png';
import logo from '../../../assets/LogoSemFundo.png';

//import Api from '../../api/api.js';



//const [codPrd, setcodPrd] = useState(" ");
//const [preco, setPreco_produto] = useState ("");
//const [categoria, setCategoria_produto] = useState ("");
//const [tamanho, setTamanho_produto] = useState ("");


/*async function buscarProduto(){
  if(codPrd < 14 || codPrd > 30){
    Alert.alert("Codigo invalido!")
    setcodPrd("")
    
  }
    try{
      const response = await Api.get(`http://26.173.109.7:8080/Servlet/servletConfig`)
      setPreco_produto(response.data.Preco_produto)
      setCategoria_produto(response.data.Categoria_produto)
      setTamanho_produto(response.data.Tamanho_produto)
      setQuantidade_produto(response.data.Quantidade_produto)
    } catch (error) {
      console.log("ERRO" + error);
    }

}*/

export default function Home() {
  return (
    <View style={estilos.container}>
      <View style={estilos.box}>
        <Image source={caminhao} style={estilos.icone}/>
        <Image source={caixa} style={estilos.icone}/>
        <Image source={logo} style={estilos.logo}/>
      </View>

      <View>
        <View style={estilos.boxCadastro}>
          <Text style={estilos.texto}>Consultar codigo do produto</Text>

          <Text style={estilos.titulo}>Pesquisar</Text>
          <TextInput placeholder='Consultar produtos' style={estilos.cadastro}  
          />

          <TextInput placeholder='Preço' style={estilos.cadastro}/>  
          <TextInput placeholder='Categoria' style={estilos.cadastro}/>
          <TextInput placeholder='Tamanho' style={estilos.cadastro}/>
          <TextInput placeholder='Quantidade' style={estilos.cadastro}/>

          <TouchableOpacity style={estilos.button} onPress={""} >
            <Text style={estilos.acessar}>CONSULTAR</Text>
          </TouchableOpacity>  
        </View>
      </View>
    </View>  
  );
}

