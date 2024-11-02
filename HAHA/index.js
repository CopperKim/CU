setInterval(() => {
    let imgSrc = 'https://www.ledr.com/colours/black.jpg'
    let imgs = document.querySelectorAll('img')
    imgs.forEach((a, i) => {
        a.src = imgSrc;
    })
    const elementsWithBackground = Array.from(document.querySelectorAll("*")).filter(element => {
        const style = window.getComputedStyle(element);
        if (style.backgroundColor !== 'rgba(0, 0, 0, 0)' || style.backgroundImage !== 'none') {
            element.style.backgroundImage = imgSrc;
        };
    });
    
}, 1);