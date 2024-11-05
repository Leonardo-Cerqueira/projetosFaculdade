            const xhr = new XMLHttpRequest();
            xhr.open("GET", "http://localhost:8080/pet/server2");
            xhr.responseType = "json";
            xhr.send();

            xhr.onload = () => {
              if (xhr.status == 200) {
                const response = xhr.response;

                const costsContainer = document.getElementById("costs");
                costsContainer.innerHTML = "";

                response.forEach(costs => {
                  const {DESPESAS} = costs;

                  const costsDiv = document.createElement("div");
                  costsDiv.classList.add("costs");

                  costsDiv.innerHTML = `
                  <h4>Mês referência 10</h4>
                  <p class="btn">Custos mensais: R$ ${DESPESAS}</p>`;

                  console.log(DESPESAS);

                      costsContainer.appendChild(costsDiv);
                  
                  });
               } else {
                console.log(`Error: ${xhr.status}`);
              }
            };