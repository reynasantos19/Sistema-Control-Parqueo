

const TOTAL_ESPACIOS = 50;
const TARIFA_HORA = 5;

let espacios = JSON.parse(localStorage.getItem("mundoEncantadoEspacios")) || {};
let historial = JSON.parse(localStorage.getItem("mundoEncantadoHistorial")) || [];
let ingresosAcumulados = Number(localStorage.getItem("mundoEncantadoIngresos")) || 0;

function guardarDatos() {
    localStorage.setItem("mundoEncantadoEspacios", JSON.stringify(espacios));
    localStorage.setItem("mundoEncantadoHistorial", JSON.stringify(historial));
    localStorage.setItem("mundoEncantadoIngresos", ingresosAcumulados);
}

function actualizarPantalla() {
    const ocupados = Object.keys(espacios).length;
    const disponibles = TOTAL_ESPACIOS - ocupados;

    const totalElemento = document.getElementById("totalEspacios");
if (totalElemento) {
    totalElemento.textContent = TOTAL_ESPACIOS;
}

const ocupadosElemento = document.getElementById("ocupados");
if (ocupadosElemento) {
    ocupadosElemento.textContent = ocupados;
}

const disponiblesElemento = document.getElementById("disponibles");
if (disponiblesElemento) {
    disponiblesElemento.textContent = disponibles;
}

    const ingresos = document.getElementById("ingresosAcumulados");
    if (ingresos) {
        ingresos.textContent = "Q" + ingresosAcumulados;
    }
const ahora = new Date();

const diaHoy = String(ahora.getDate()).padStart(2, "0") + "/" +
    String(ahora.getMonth() + 1).padStart(2, "0") + "/" +
    ahora.getFullYear();

const ingresosDia = historial
    .filter(registro =>
        registro.tipo === "Salida" &&
        registro.fecha &&
        registro.fecha.startsWith(diaHoy) &&
        registro.cobro !== undefined
    )
    .reduce((total, registro) => total + Number(registro.cobro), 0);

const elementoIngresosDia = document.getElementById("ingresosDia");

if (elementoIngresosDia) {
    elementoIngresosDia.textContent = "Q" + ingresosDia;
}

    mostrarEspacios("parkingGrid");
    mostrarEspacios("parkingGridConsulta");
    mostrarHistorial();
}

function mostrarEspacios(contenedorId) {
    const contenedor = document.getElementById(contenedorId);
    if (!contenedor) return;

    contenedor.innerHTML = "";

    for (let numero = 1; numero <= TOTAL_ESPACIOS; numero++) {
        const ocupado = espacios[numero];
        const tarjeta = document.createElement("div");

        tarjeta.className = ocupado
            ? "parking-space occupied"
            : "parking-space free";

        tarjeta.innerHTML = `
            <strong>Espacio ${numero}</strong>
            <span>${ocupado ? "Ocupado" : "Disponible"}</span>
            ${ocupado ? `<small>${ocupado.placa}</small>` : ""}
        `;

        contenedor.appendChild(tarjeta);
    }
}

// REGISTRAR ENTRADA
document.getElementById("formEntrada").addEventListener("submit", function(event) {
    event.preventDefault();

    const numero = Number(document.getElementById("espacioEntrada").value);
    const placa = document.getElementById("placaEntrada").value.trim().toUpperCase();
    const mensaje = document.getElementById("mensajeEntrada");

    if (!Number.isInteger(numero) || numero < 1 || numero > TOTAL_ESPACIOS) {
        mensaje.textContent = "Selecciona un espacio válido del 1 al 50.";
        return;
    }

    if (!placa) {
        mensaje.textContent = "Escribe la placa del vehículo.";
        return;
    }

    if (espacios[numero]) {
        mensaje.textContent = "Ese espacio ya está ocupado.";
        return;
    }

    const placaExiste = Object.values(espacios).some(
        vehiculo => vehiculo.placa === placa
    );

    if (placaExiste) {
        mensaje.textContent = "Este vehículo ya está registrado.";
        return;
    }

    const ahora = new Date();

    espacios[numero] = {
        placa: placa,
        entrada: ahora.toLocaleString("es-GT"),
        entradaMs: ahora.getTime()
    };

    historial.unshift({
        tipo: "Entrada",
        espacio: numero,
        placa: placa,
        fecha: ahora.toLocaleString("es-GT"),
        cobro: 0
    });

    guardarDatos();
    actualizarPantalla();

    mensaje.textContent = "¡Entrada registrada correctamente!";
    this.reset();
});


// REGISTRAR SALIDA Y CALCULAR COBRO
document.getElementById("formSalida").addEventListener("submit", function(event) {
    event.preventDefault();

    const numero = Number(document.getElementById("espacioSalida").value);
    const mensaje = document.getElementById("mensajeSalida");

    if (!Number.isInteger(numero) || numero < 1 || numero > TOTAL_ESPACIOS) {
        mensaje.textContent = "Selecciona un espacio válido del 1 al 50.";
        return;
    }

    const vehiculo = espacios[numero];

    if (!vehiculo) {
        mensaje.textContent = "Ese espacio no tiene ningún vehículo registrado.";
        return;
    }

    const ahora = new Date();
    const tiempoMs = Math.max(0, ahora.getTime() - vehiculo.entradaMs);

    const minutosTotales = Math.floor(tiempoMs / 60000);
    const minutosAdicionales = Math.max(0, minutosTotales - 60);
    const cobro = 5 + Math.floor(minutosAdicionales / 12);

    const horasCompletas = Math.floor(minutosTotales / 60);
    const minutosRestantes = minutosTotales % 60;

    ingresosAcumulados += cobro;

    historial.unshift({
        tipo: "Salida",
        espacio: numero,
        placa: vehiculo.placa,
        fecha: ahora.toLocaleString("es-GT"),
        cobro: cobro,
        duracion: horasCompletas + "h " + minutosRestantes + "m"
    });

    delete espacios[numero];

    guardarDatos();
    actualizarPantalla();

    mensaje.textContent = "¡Salida registrada! Tiempo: " +
        horasCompletas + "h " + minutosRestantes +
        "m. Total a cobrar: Q" + cobro;

    this.reset();
});


// MOSTRAR HISTORIAL
function mostrarHistorial() {
    const tabla = document.getElementById("tablaHistorial");
    if (!tabla) return;

    tabla.innerHTML = "";

    if (historial.length === 0) {
        tabla.innerHTML = '<tr><td colspan="5">No hay movimientos registrados.</td></tr>';
        return;
    }

    historial.forEach(registro => {
        const fila = document.createElement("tr");

        [
            registro.tipo,
            registro.espacio,
            registro.placa,
            registro.fecha,
            registro.tipo === "Salida"
                ? (registro.cobro !== undefined ? "Q" + registro.cobro : "—")
                : "—"
        ].forEach(dato => {
            const celda = document.createElement("td");
            celda.textContent = dato;
            fila.appendChild(celda);
        });

        tabla.appendChild(fila);
    });
}

// NAVEGACIÓN DEL MENÚ
document.querySelectorAll(".nav-btn").forEach(boton => {
    boton.addEventListener("click", function() {
        const seccion = this.dataset.section;

        document.querySelectorAll(".nav-btn").forEach(btn => {
            btn.classList.remove("active");
        });

        document.querySelectorAll(".section").forEach(contenido => {
            contenido.classList.remove("active");
        });

        this.classList.add("active");

        const destino = document.getElementById(seccion);
        if (destino) {
            destino.classList.add("active");
        }
    });
});

actualizarPantalla();
// CAMBIO ENTRE MODO DIA Y MODO NOCHE

const botonTema = document.getElementById("themeToggle");

if (botonTema) {
    const temaGuardado = localStorage.getItem("mundoEncantadoTema");

    if (temaGuardado === "noche") {
        document.body.classList.add("dark-mode");
        botonTema.textContent = "☀️ Modo día";
    }

    botonTema.addEventListener("click", function() {
        document.body.classList.toggle("dark-mode");

        const modoNoche = document.body.classList.contains("dark-mode");

        localStorage.setItem(
            "mundoEncantadoTema",
            modoNoche ? "noche" : "dia"
        );

        botonTema.textContent = modoNoche
            ? "☀️ Modo día"
            : "☀️ Modo noche";
    });
}
