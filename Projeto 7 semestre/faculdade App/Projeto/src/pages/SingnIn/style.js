import { StyleSheet } from "react-native";

const estilos = StyleSheet.create ({
    container: {
        flex:1,
        backgroundColor: '#555353',
    },

    bemVindo: {
        height: 100,
        fontSize: 30,
        fontWeight: 'bold',
        color: '#FFFFFF',
        marginTop: 200, 
        paddingStart: '5%'       
    },

    box: {
        flex: 1,
        backgroundColor: '#FFFFFF',
        borderTopLeftRadius: 20,
        borderTopRightRadius: 20,
    },

    textoEmail: {
        fontSize: 20,
        color: '#000000',
        marginBottom: 10,
        marginTop: 10,
        paddingStart: '5%'   
    },

    box1: {
        marginHorizontal: '5%',
        borderWidth: 2,
        borderRadius: 5,
        width: 350,
        height: 40,
        marginBottom: 20,   
        color: '#000000', 
        paddingLeft: 5,     
    },

    textoSenha: {
        fontSize: 20,
        color: '#000000',
        marginBottom: 10,
        paddingStart: '5%'
    },

    button: {
        height: 40,
        width: 250,
        backgroundColor: '#555353',
        borderRadius: 10,
        alignItems: 'center',
        marginHorizontal: 70,
        marginTop: 10
    },

    acessar: {
        color: '#FFFFFF',
        fontSize: 18,
        marginTop: 5,
    },
});

export default estilos;