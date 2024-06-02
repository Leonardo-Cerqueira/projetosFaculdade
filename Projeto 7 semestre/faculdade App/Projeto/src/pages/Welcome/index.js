import React from 'react';
import {Text, View, TouchableOpacity } from 'react-native';
import {useNavigation} from '@react-navigation/native';

import * as Animatable from 'react-native-animatable';

import estilos from './style';
import Logo from '../../../assets/LogoSemFundo.png';

export default function Welcome() {
  const navigation = useNavigation();
  return (
    <View style={estilos.container}>
      <View style={estilos.boxImg}>
        <Animatable.Image animation='slideInDown' source={Logo} style={estilos.img}/>
      </View>  

      <Animatable.View delay={600} animation= 'fadeInUp' style ={estilos.box}>
        <Text style={estilos.title}>Organize o seu estoque com a melhor plataforma de gerenciamento!</Text>
        <TouchableOpacity style={estilos.button} onPress={ () => navigation.navigate('SingnIn')}>
          <Text style={estilos.textoAcesso}>Acessar</Text>
        </TouchableOpacity>
      </Animatable.View>
    </View>
  );
}

