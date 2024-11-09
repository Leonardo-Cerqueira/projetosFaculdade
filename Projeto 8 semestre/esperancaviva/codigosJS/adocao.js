const xhr = new XMLHttpRequest();
xhr.open("GET", "http://localhost:8080/pet/server");
xhr.responseType = "json";
xhr.send();

xhr.onload = () => {
  if (xhr.status == 200) {
    const response = xhr.response;

    const animalsContainer = document.getElementById("animais");
    animalsContainer.innerHTML = "";

    response.forEach(animals => {
      const { ID_ANIMAL, ESPECIE, NOME_RACA, NOME, GENERO, ESTADO } = animals;

      const animalsForm = document.createElement("form");
      animalsForm.id = `Form ${ID_ANIMAL}`;
      animalsForm.classList.add("animals");

      animalsForm.innerHTML = `
                      <h1>Registro animal: ${ID_ANIMAL}</h1>
                      <h4>Espécie: ${ESPECIE} <br> 
                      Nome da Raça: ${NOME_RACA} <br>
                      Nome do Animal: ${NOME} <br> 
                      Gênero: ${GENERO} <br> 
                      Estado em que foi encontrado: ${ESTADO} <br> 
                      <input type="submit" value="Adotar">
                      <input id='${ID_ANIMAL}' type="number" value='${ID_ANIMAL}' hidden>
                      </h4>`;

      animalsContainer.appendChild(animalsForm);

      animalsForm.addEventListener('submit', evento => {

        evento.preventDefault();

        var adot = "1";
        var id = document.getElementById(`${ID_ANIMAL}`).value;

        const xhr = new XMLHttpRequest();

        xhr.open("POST", "http://localhost:8080/pet/server");

        xhr.setRequestHeader("Content-Type", "application/json");
        var corp = JSON.stringify({
          id: id,
          adot: adot
        });

        console.log(corp);

        xhr.send(corp);

        xhr.onload = () => {
          console.log(xhr.status);
          xhr.abort();
          console.log("Conexão fechada")
          location.reload(true);

          window.alert("Parabéns!!! Sua intenção de adoção foi registrada!!! Diriga-se ao endereço da ong para completar a adoção. Leve os documentos necessários para realizar seu cadastro (RG, Comprovante de residência etc)!");

        };


      });
    });
  } else {
    console.log(`Error: ${xhr.status}`);
  }

};
