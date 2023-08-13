document.addEventListener('DOMContentLoaded', function () {
    const generateButton = document.getElementById('generateButton');
    const textInput = document.getElementById('textInput');
    const qrCodeContainer = document.getElementById('qrCodeContainer');
    const downloadButton = document.getElementById('downloadButton');

    generateButton.addEventListener('click', generateQRCode);

    async function generateQRCode() {
        const text = textInput.value;
        if (text.trim() === '') {
            alert('Please enter a valid text or URL.');
            return;
        }

        try {
            const response = await fetch(`https://api.qrserver.com/v1/create-qr-code/?data=${encodeURIComponent(text)}&size=200x200`);
            if (!response.ok) {
                throw new Error('QR code generation failed.');
            }

            qrCodeContainer.innerHTML = '';
            const qrCodeImageURL = URL.createObjectURL(await response.blob());

            const img = document.createElement('img');
            img.src = qrCodeImageURL;
            img.alt = 'QR Code';
            qrCodeContainer.appendChild(img);

            downloadButton.href = qrCodeImageURL;
            downloadButton.classList.remove('hidden');
        } catch (error) {
            console.error(error);
            alert('An error occurred while generating the QR code.');
        }
    }
});
