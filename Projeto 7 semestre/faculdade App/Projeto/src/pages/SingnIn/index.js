import React from 'react';
import {Text, View, TextInput, TouchableOpacity} from 'react-native';
import {useNavigation} from '@react-navigation/native';

import * as Animatable from 'react-native-animatable';

import estilos from './style';

export default function SingnIn() {
  const navigation = useNavigation();
  return (
    <View style={estilos.container}>
      
      <Animatable.View Animatable='fadeInLeft' delay={1000}>
        <Text style={estilos.bemVindo}>Seja Bem-Vindo!</Text>
      </Animatable.View>

      <Animatable.View Animatable='fadeInUp' delay={800} style={estilos.box} >
    
        <Text style={estilos.textoEmail}>E-MAIL</Text>
        <TextInput placeholder='Digite um email...'style={estilos.box1}/>
        
        <Text style={estilos.textoSenha}>SENHA</Text>
        <TextInput placeholder='Digite uma Senha...' style={estilos.box1}/>
      
        <TouchableOpacity style={estilos.button} onPress={ () => navigation.navigate('Home')}>
          <Text style={estilos.acessar}>ACESSAR</Text>
        </TouchableOpacity>
      </Animatable.View>
    
    </View>
  );
}

