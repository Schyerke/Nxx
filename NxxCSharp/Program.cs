using System;

namespace NxxCSharp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            while (true)
            {
                Console.Write("> ");
                string? line = Console.ReadLine();
                if(line == null)
                {
                    break;
                }
                Lexer lexer = new Lexer(line);
                SyntaxToken? token;
                do
                {
                    token = lexer.Lex();
                    
                    if(token.Kind == SyntaxKind.BadToken)
                    {
                        Console.WriteLine("Bad Token.");
                        continue;
                    }

                    Console.WriteLine($"Token text: '{token.Text}', Token Kind: '{token.Kind}'");

                } while (token != null && token.Kind != SyntaxKind.EOF);
            }
        }
    }
}