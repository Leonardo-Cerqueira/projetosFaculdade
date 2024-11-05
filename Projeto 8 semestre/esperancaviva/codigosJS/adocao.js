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
                  const { ID_ANIMAL, ESPECIE, NOME_RACA, NOME, GENERO, ESTADO} = animals;

                  const animalsDiv = document.createElement("div");
                  animalsDiv.classList.add("animals");

                  animalsDiv.innerHTML = `
                      <p class="btn">Número do animal: ${ID_ANIMAL}</p>
                      <h2>Espécie: ${ESPECIE}</h2>
                      <h2>Nome da Raça: ${NOME_RACA}</h2>
                      <h2>Nome do Animal: ${NOME}</h2>
                      <h2>Gênero: ${GENERO}</h2>
                      <h2>Estado em que foi encontrado: ${ESTADO}</h2>`;

                  animalsContainer.appendChild(animalsDiv);

                  });
               } else {
                console.log(`Error: ${xhr.status}`);
              }
            };