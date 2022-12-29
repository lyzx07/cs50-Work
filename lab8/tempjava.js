//run script once DOMis loaded
            document.addEventListener('DOMContentLoaded', function()
            {
                //when correct answer is clicked, turn color to green
                let correct = document.querySelector('.correct');
                correct.addEventListener('click', function()
                {
                    correct.style.backgroundColor = 'green';
                    document.querySelector('#feedback1').innerHTML = 'Correct!';
                });

                //when any incorrect answer is clicked, turn color to red
                let incorrects = document.querySelectorAll('.incorrect');
                for (let i = 0; i < incorrects.length; i++)
                {
                    incorrects[i].addEventListener('click', function()
                    {
                        incorrects[i].style.backgroundColor = 'red';
                        document.querySelector('#feedback1').innerHTML = 'Incorrect';
                    });
                }

                //check free response submission
                document.querySelector('#check').addEventListener('click', function()
                {
                    let input = document.querySelector('input'):
                    if (input.value === 'Phil' || input.value === 'Phillip')
                    {
                        input.style.backgroundColor = 'green';
                        document.querySelector('#feedback2').innerHTML = 'Correct!';
                    }

                    else
                    {
                        input.style.backgroundColor = 'red';
                        document.querySelector('#feedback2').innerHTML = 'Incorrect';
                    }
                });
            });
            
            
            
            
            
             function functionTwo(){
            var incorrect = document.querySelector(".incorrect");
            incorrect.innerHTML='Incorrect';
            incorrect.style.backgroundColor='red';
        }