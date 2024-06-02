import { StyleSheet } from "react-native";

const estilos = StyleSheet.create ({
    container: {
        flex: 1,
        backgroundColor: '#555353',
    },

    boxImg: {
        height: 500,
        width: '100%',
        alignItems: 'center',
        alignContent: 'center', 
    },

    img: {
        width: 250,
        height: 250,
        backgroundColor: '#ffffff',
        borderRadius: 125,
        borderColor: '#000000',
        borderWidth: 3, 
        marginTop: 100,     
    },

    box: {
        backgroundColor: '#FFFFFF',
        height: 300,
        borderTopLeftRadius: 25,
        borderTopRightRadius: 25,
        paddingHorizontal: '5%',
    },

    title: {
        fontSize: 20,
        fontWeight: 'bold',
        textAlign: 'center',
        marginBottom: 20,
        marginTop: 20,
    },

    text: {
        fontSize: 18,
        textAlign: 'center',
    },

    destaque: {
        fontWeight: 'bold',
    },

    button: {
        backgroundColor: '#555353',
        height: 40,
        width: 250,
        marginLeft: 50,
        bottom: '-15%',
        borderRadius: 10,
    },

    textoAcesso: {
        fontSize: 18,
        textAlign: 'center',
        marginTop: 5,
        color: '#FFFFFF',
        fontWeight: 'bold',
    },
});

export default estilos;