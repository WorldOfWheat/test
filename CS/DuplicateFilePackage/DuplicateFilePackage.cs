using System.Security.Cryptography;
using System.Numerics;
using MerkleTree;

namespace DuplicateFilePackage
{
    public enum HashAlgorithm
    {
        MD5,
        SHA1,
        SHA256,
        SHA512
    }

    public class PathParameters
    {
        LinkedList<string> InputPaths = new LinkedList<string>();
        string OutputPath = "";
        HashAlgorithm hashAlgorithm = HashAlgorithm.SHA256;
        bool DirectDelete = false;
        bool IncludeAllDirectories = true;
    }

    public interface IDuplicateFileService
    {
        void Duplicate(PathParameters parameters);
    }

    public class DuplicateFilePackageService : IDuplicateFileService
    {
        void IDuplicateFileService.Duplicate(PathParameters parameters)
        {
        }
    }
}