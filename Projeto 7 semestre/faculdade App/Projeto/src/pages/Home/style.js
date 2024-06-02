import { StyleSheet } from "react-native";

const estilos = StyleSheet.create ({
    container:{
        flex: 1,
        alignContent: 'center',
        alignItems: 'center', 
        backgroundColor: '#555353',       
    },

    box: {
        height: 100,
        width: '100%',
        flexDirection: 'row',
    },

    icone: {
        marginTop: 20,
        marginLeft: 20,
    },

    logo: {
        width: 130,
        height: 130,
        marginTop: -20,
        marginLeft: 30 
    },

    boxCadastro: {
        backgroundColor: '#FFFFFF',
        height: 500,
        width: 350,
        marginTop: 50,
        paddingHorizontal: 10,
        borderRadius: 5,
    },

    texto: {
        fontSize: 22,
        textAlign: 'center',
        fontWeight: 'bold',
        marginTop: 15,
    },

    titulo: {
        marginTop: 15,
        fontSize: 18,
        fontWeight: 'bold',
    },

    cadastro: {
        height: 40,
        width: 330,
        borderWidth: 1,
        borderRadius: 5,
        marginBottom: 10,
        paddingLeft: 5,
    },

    button:{
        backgroundColor: '#555353',
        height: 40,
        width: 150,
        borderRadius: 5,
        marginLeft: 70,
        marginTop: 10,
    },

    acessar: {
        marginTop: 10,
        textAlign: 'center',
        color: '#FFFFFF',
        fontWeight: 'bold',
    },
});

export default estilos;