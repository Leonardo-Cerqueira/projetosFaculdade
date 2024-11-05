const xhr = new XMLHttpRequest();
xhr.open("GET", "http://localhost:8080/pet/server3");
xhr.responseType = "json";
xhr.send();

xhr.onload = () => {
  if (xhr.status == 200) {
    const response = xhr.response;

    const donationContainer = document.getElementById("donation");
    donationContainer.innerHTML = "";

    response.forEach(donation => {
      const {DOACOES} = donation;

      const donationDiv = document.createElement("div");
      donationDiv.classList.add("donation");

      donationDiv.innerHTML = `
      <h4>Mês referência 10</h4>
      <p class="btn">Custos mensais: R$ ${DOACOES}</p>`;

      console.log(DOACOES);

      donationContainer.appendChild(donationDiv);
      
      });
   } else {
    console.log(`Error: ${xhr.status}`);
  }
};