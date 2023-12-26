using aula_1;

int n1, n2;

Console.Write("Digite o primeiro número: ");
n1 = Convert.ToInt32(Console.ReadLine());

Console.Write("Digite o segundo número: ");
n2 = Convert.ToInt32(Console.ReadLine());

int soma = n1 + n2;

Console.WriteLine("A soma desses números é: " + soma);

Console.Write("Digite seu nome: ");
string nome = Console.ReadLine();

var pessoa = new Pessoa(nome);

Console.WriteLine("Seu nome é " + pessoa.Nome);
